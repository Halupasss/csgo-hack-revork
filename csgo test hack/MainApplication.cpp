#include "includes.h"

#define null NULL
#define not !
#define and &&
#define or ||
#define is ==
#define not_is !=

C_MainApplication::C_MainApplication()
{
	this->pMainThread = *hack::mainThread;
	this->pBhopThread = *hack::bhopThread;
	this->p_hModule = nullptr;
}

void C_MainApplication::run(HMODULE* p_hModule)
{
	this->p_hModule = p_hModule;

	HANDLE mainHandle = CreateThread(
		null,
		null,
		(LPTHREAD_START_ROUTINE)&this->pMainThread,
		&this->p_hModule,
		null,
		null);

	if (mainHandle not_is null)
	{
		CloseHandle(mainHandle);
	}
}

uintptr_t WINAPI hack::mainThread(HMODULE hModule)
{
	while (pC_MainApplication->hackstate is HACKSTATE_NORMAL)
	{
		if (GetAsyncKeyState(settings::keys::endButton))
		{
			pC_MainApplication->hackstate = HACKSTATE_OFF;
		}
	}

	FreeLibraryAndExitThread(hModule, 0);
}