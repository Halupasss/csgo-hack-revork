#include "includes.h"

void C_MainApplication::run(HMODULE hModule)
{
	this->mainThreadHandle = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)C_MainApplication::mainThread, hModule, NULL, NULL);

	if (this->mainThreadHandle != NULL)
	{
		CloseHandle(this->mainThreadHandle);
	}
}

void C_MainApplication::release()
{
	return;
}