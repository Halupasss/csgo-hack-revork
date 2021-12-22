#include "includes.h"

#define not !
#define and &&
#define or ||
#define is ==

namespace bhop
{
	static C_LocalPlayer localPlayer;

	void run()
	{
		int localPlayerHealth = localPlayer.getHealth();
		int localPlayerFlags = localPlayer.getFlags();

		if (localPlayer.isAlive())
		{
			if (localPlayerFlags is cVars::flags::fOnGround)
			{
				localPlayer.jump();
			}
		}
	}
}

uintptr_t __stdcall hack::bhopThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::bhop)
		{
			if (GetAsyncKeyState(settings::keys::jumpButton))
			{
				bhop::run();
			}		
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}