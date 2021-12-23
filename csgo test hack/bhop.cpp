#include "includes.h"

namespace bhop
{
	static C_LocalPlayer localPlayer;

	void run()
	{
		int localPlayerHealth = localPlayer.getHealth();
		int localPlayerFlags = localPlayer.getFlags();
		Vec3 localPlayerVelocity = localPlayer.getVelocity();

		if (localPlayerVelocity.x >= 0.01 or
			localPlayerVelocity.y >= 0.01 or
			localPlayerVelocity.z >= 0.01
		) {
			if (localPlayer.isAlive())
			{
				if (localPlayerFlags is cVars::flags::fOnGround)
				{
					localPlayer.jump();
				}
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