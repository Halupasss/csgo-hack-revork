#include "includes.h"

C_MainApplication::C_MainApplication()
{
	this->pMainThread = (void*)hack::mainThread;
	this->pBhopThread = (void*)hack::bhopThread;
	this->pNeonGlowThread = (void*)hack::neonGlowThread;
	this->pNoFlashThread = (void*)hack::noFlashThread;
	this->pAimBotThread = (void*)hack::aimbotThread;
	this->pRadarHackThread = (void*)hack::radarHackThread;
	this->pRecoilControlSystem = (void*)hack::recoilControlSystemThread;
	this->pTriggerBot = (void*)hack::triggerBotThread;

	this->hackstate = HACKSTATE_NORMAL;
	this->hModule = null;
}

void C_MainApplication::run(HMODULE hModule)
{
	this->hModule = hModule;

	HANDLE mainHandle = CreateThread(
		null,
		null,
		(LPTHREAD_START_ROUTINE)this->pMainThread,
		this->hModule,
		null,
		null);
}

void C_MainApplication::initModule(void* pModule)
{
	HANDLE tHandle = CreateThread(
		null,
		null,
		(LPTHREAD_START_ROUTINE)pModule,
		&this->hModule,
		null,
		null);
}

void C_MainApplication::initAllModules()
{
	this->initModule(this->pBhopThread);
	this->initModule(this->pNeonGlowThread);
	this->initModule(this->pNoFlashThread);
	this->initModule(this->pAimBotThread);
	this->initModule(this->pRadarHackThread);
	this->initModule(this->pRecoilControlSystem);
	this->initModule(this->pTriggerBot);
}

uintptr_t WINAPI hack::mainThread(HMODULE hModule)
{
	MainApplication.initAllModules();

	while (MainApplication.hackstate is HACKSTATE_NORMAL)
	{
		if (GetAsyncKeyState(settings::keys::endButton))
		{
			MainApplication.hackstate = HACKSTATE_OFF;
		}
	}
	FreeLibraryAndExitThread(hModule, 0);
}