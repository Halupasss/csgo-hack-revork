#pragma once

#define HACKSTATE_NORMAL true
#define HACKSTATE_OFF    false

namespace hack
{
	uintptr_t WINAPI mainThread(HMODULE hModule);
	uintptr_t WINAPI bhopThread(HMODULE hModule);
}

class C_MainApplication
{
private:
	HMODULE *p_hModule;
private:
	void* pMainThread;
	void* pBhopThread;
public:
	bool hackstate = HACKSTATE_NORMAL;
public:
	void run(HMODULE *p_hModule);
public:
	C_MainApplication();
};

extern C_MainApplication* pC_MainApplication;