#pragma once

#define HACKSTATE_NORMAL true
#define HACKSTATE_OFF    false

namespace hack
{
	uintptr_t __stdcall mainThread(HMODULE hModule);
	uintptr_t __stdcall bhopThread(HMODULE hModule);
	uintptr_t __stdcall neonGlowThread(HMODULE hModule);
	uintptr_t __stdcall noFlashThread(HMODULE hModule);
	uintptr_t __stdcall aimbotThread(HMODULE hModule);
}

#ifndef MAINAPPLICATION_H_
#define MAINAPPLICATION_H_

class C_MainApplication
{
private:
	HMODULE hModule;
private:
	void* pMainThread;
	void* pBhopThread;
	void* pNeonGlowThread;
	void* pNoFlashThread;
	void* pAimBotThread;
public:
	bool hackstate;
public:
	void run(HMODULE hModule);
	void initAllModules();
	void initModule(void* pModule);
public:
	C_MainApplication();
};

#endif

extern C_MainApplication MainApplication;