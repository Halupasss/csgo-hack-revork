#include "includes.h"

#define not !
#define and &&
#define or ||
#define is ==

C_LocalPlayer * pLocalPlayer = new C_LocalPlayer();

void bhop()
{
	int localPlayerHealth = pLocalPlayer->getHealth();
	int localPlayerArmor  = pLocalPlayer->getArmor();
	int localPlayerFlags  = pLocalPlayer->getFlags();

	if (pLocalPlayer->isAlive())
	{
		if (localPlayerFlags is cVars::flags::fOnGround)
		{
			pLocalPlayer->jump();
		}
	}
}

uintptr_t WINAPI hack::bhopThread(HMODULE hModule)
{
	while (pC_MainApplication->hackstate is HACKSTATE_NORMAL)
	{
		if (settings::modules::bhop)
		{
			bhop();
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}