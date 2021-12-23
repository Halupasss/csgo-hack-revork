#include "includes.h"

namespace triggerBot
{
	static C_LocalPlayer localPlayer;
	static C_GameEngine gameEngine;

	void run()
	{
		int crosshairID = localPlayer.getCrosshairID();	

		if ((crosshairID is_not null) and (crosshairID <= cVars::game::maxNumOfPlayersInServer))
		{
			C_Entity entity(crosshairID - 1);

			if (not entity.isAlive())
				return;

			int localPlayerTeamNum = localPlayer.getTeamNum();
			int entityTeam = entity.getTeamNum();

			if (entityTeam is_not localPlayerTeamNum)
			{
				localPlayer.shoot();
				Sleep(settings::triggerBot::delay);
			}
		}
	}
}

uintptr_t __stdcall hack::triggerBotThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::triggerBot)
		{
			triggerBot::run();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}