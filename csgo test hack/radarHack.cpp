#include "includes.h"

namespace radarHack
{
	static C_LocalPlayer localPlayer;
	static C_EntityList entityList;

	void run()
	{
		int localPlayerTeamNum = localPlayer.getTeamNum();

		for (int i = cVars::game::meIndex; i < cVars::game::maxNumOfPlayersInServer; i++)
		{
			C_Entity entity(entityList[i]);

			if (not entityList[i])
				continue;

			if (not entity.isAlive())
				continue;

			int entityTeamNum = entity.getTeamNum();
			
			if (localPlayerTeamNum is entityTeamNum)
				continue;

			entity.detect();
		}
	}
}

uintptr_t __stdcall hack::radarHackThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::radarHack)
		{
			radarHack::run();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}