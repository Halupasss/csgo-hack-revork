#pragma once

static class C_MainApplication
{
private:
	void mainThread(HMODULE hModule);
	HANDLE mainThreadHandle;
public:
	void run(HMODULE hModule);
	void release();
};

extern C_MainApplication *pC_MainApplication;