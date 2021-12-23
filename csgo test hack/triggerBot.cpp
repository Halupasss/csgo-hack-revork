#include "includes.h"

namespace triggerBot
{
	static C_LocalPlayer localPlayer;
	static C_GameEngine gameEngine;

	void run()
	{
		int crosshairID = localPlayer.getCrosshairID();	

		C_Entity entity(crosshairID - 1);

		int localPlayerTeamNum = localPlayer.getTeamNum();
		int entityTeam = entity.getTeamNum();

		localPlayer.shoot();
		Sleep(settings::triggerBot::delay);
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