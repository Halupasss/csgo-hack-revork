#include "includes.h"

#define is ==
#define and &&
#define or ||
#define none NULL

namespace noFlash
{
	static C_LocalPlayer localPlayer;

	void run()
	{
		int localPlayerFlashDur = localPlayer.getFlashDuration();

		if (localPlayerFlashDur > 0)
		{
			localPlayer.nullifyFlashDuration();
		}
	}
}

uintptr_t __stdcall hack::noFlashThread(HMODULE hModule)
{
	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::noFlash)
		{
			noFlash::run();

			Sleep(100);
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}