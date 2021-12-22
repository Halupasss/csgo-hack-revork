#include "includes.h"

#define M_PI 3.14159265358979323846
#define is ==
#define or ||
#define and &&
#define not !
#define none NULL

namespace aimBot
{
	static C_LocalPlayer localPlayer;
	static C_EntityList entityList;
	static C_GameEngine engine;

	Vec3 getAngle(Vec3 &dest, Vec3 &orig)
	{
		Vec3 delta;
		delta.x = orig.x - dest.x;
		delta.y = orig.y - dest.y;

		dest.x = orig.x - delta.x / (5.f * 15);
		dest.y = orig.y - delta.y / (5.f * 15);

		return dest;
	}

	Vec3 calculateAngle(Vec3 &viewAngle, Vec3 &entityPos)
	{
		float d_x = viewAngle.x - entityPos.x;
		float d_y = viewAngle.y - entityPos.y;
		float d_z = viewAngle.z - entityPos.z;

		float hyp = sqrt(d_x * d_x + d_y * d_y + d_z * d_z);

		float x = atan(d_z / hyp) * 180 / M_PI;
		float y = atan(d_y / d_x) * 180 / M_PI;

		if (d_x > 0.0)
			y += 180;

		return Vec3{ x, y, 0 };
	}

	Vec3 normalizeAngles(Vec3 &angle)
	{
		if (angle.x > 89)
		{
			angle.x -= 360;
		}
		else if (angle.x < -89)
		{
			angle.x += 360;
		}
		else if (angle.y > 180)
		{
			angle.y -= 360;
		}
		else if (angle.y < -180)
		{
			angle.y += 360;
		}

		return angle;
	}

	uintptr_t getBestTarget()
	{
		uintptr_t resultTarget = NULL;

		float oldDiff = FLT_MAX;
		float newDiff = NULL;

		for (int i = cVars::game::meIndex; i < cVars::game::maxNumOfPlayersInServer; i++)
		{
			C_Entity entity(entityList[i]);

			int entityHealth = entity.getHealth();
			int entityTeamNum = entity.getTeamNum();
			int entitySpottedByMask = entity.isSpottedByMask();
			int localPlayerTeamNum = localPlayer.getTeamNum();
			int localPlayerCrosshairID = localPlayer.getCrosshairID();

			if (not entity.isAlive())
				continue;

			if (entityTeamNum is localPlayerTeamNum)
				continue;

			if (not (entitySpottedByMask & (1 << localPlayerCrosshairID)) && settings::aimbot::aimTroughWalls)
				continue;

			Vec3 entityHeadBonePos = engine.getBonePos(entityList[i], settings::aimbot::targetBone);
			Vec3 myViewAngles = engine.getMyViewAngles();
			Vec3 angleDifference = calculateAngle(myViewAngles, entityHeadBonePos);

			newDiff = angleDifference.x;
			if (newDiff < oldDiff)
			{
				oldDiff = newDiff;
				resultTarget = entityList[i];
			}
		}
		return resultTarget;
	}

	void run()
	{
		uintptr_t entity = getBestTarget();

		C_Entity mEntity(entity);

		Vec3 localPlayerPos = localPlayer.getPosition();
		Vec3 entityBonePos = engine.getBonePos(entity, settings::aimbot::targetBone);
		entityBonePos.z += *(float*)(LOCALPLAYER + offsets::m_vecViewOffset + 0x8);

		Vec3 angleDifference = calculateAngle(localPlayerPos, entityBonePos);
		Vec3 myViewAngles = engine.getMyViewAngles();
		Vec3 resultAngles = normalizeAngles(angleDifference);

		engine.setViewAngles(getAngle(myViewAngles, resultAngles));
	}
}

uintptr_t __stdcall hack::aimbotThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::aimBot)
		{
			aimBot::run();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}