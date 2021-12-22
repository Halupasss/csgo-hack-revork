#include "includes.h"

#define not !
#define and &&
#define or ||
#define is ==

namespace neonGlow
{
	static C_LocalPlayer localPlayer;
	static C_EntityList entityList;
	static C_GameEngine gameEngine;

	void run()
	{
		int localPlayerTeamNum = localPlayer.getTeamNum();
		uintptr_t glowManager = gameEngine.getGlowManager();

		for (int i = cVars::game::meIndex; i < cVars::game::maxNumOfPlayersInServer; i++)
		{
			C_Entity entity(entityList[i]);

			int entityHealth = entity.getHealth();
			int entityTeamNum = entity.getTeamNum();
			int entityGlowIndex = entity.getGlowIndex();

			if (not entity.isAlive())
				continue;

			if (entityTeamNum is localPlayerTeamNum)
			{
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x8) = settings::neonGlow::myTeam::color[0];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0xC) = settings::neonGlow::myTeam::color[1];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x10) = settings::neonGlow::myTeam::color[2];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x14) = settings::neonGlow::myTeam::alpha;
			}
			else
			{
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x8) = settings::neonGlow::entityTeam::color[0];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0xC) = settings::neonGlow::entityTeam::color[1];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x10) = settings::neonGlow::entityTeam::color[2];
				*(float*)(glowManager + (entityGlowIndex * 0x38) + 0x14) = settings::neonGlow::entityTeam::alpha;
			}

			*(bool*)(glowManager + (entityGlowIndex * 0x38) + 0x28) = TRUE;
			*(bool*)(glowManager + (entityGlowIndex * 0x38) + 0x29) = FALSE;
		}
	}
}

uintptr_t __stdcall hack::neonGlowThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::neonGlow)
		{
			neonGlow::run();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}