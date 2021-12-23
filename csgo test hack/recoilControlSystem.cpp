#include "includes.h"

namespace recoilControlSystem
{
	static C_LocalPlayer localPlayer;
	static C_GameEngine gameEngine;

	static Vec3 oPunch;

	void run()
	{
		int shotsFired = localPlayer.getShotsFired();

		if (shotsFired < 2)
			return;

		Vec3 viewAngles = gameEngine.getMyViewAngles() * cVars::game::aimPunchAngleCoefficient;
		Vec3 punchAngle = gameEngine.getAimPunchAngle() * cVars::game::aimPunchAngleCoefficient;
		Vec3 resultAngle = (viewAngles + oPunch) - punchAngle;

		gameEngine.setViewAngles(resultAngle);

		oPunch = punchAngle;	
	}
}

uintptr_t __stdcall hack::recoilControlSystemThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::recoilControlSystem)
		{
			recoilControlSystem::run();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}