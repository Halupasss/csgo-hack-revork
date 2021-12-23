#include "includes.h"

void C_DirectXManager::set_pDevice(LPDIRECT3DDEVICE9 pDevice)
{
	this->pDevice = pDevice;
}

BOOL __stdcall enumWindowsCallback(HWND handle, LPARAM lParam)
{
	DWORD wndProcId;

	GetWindowThreadProcessId(handle, &wndProcId);

	if (GetCurrentProcessId() != wndProcId)
		return true;

	return false;
}

HWND C_DirectXManager::getProcessWindow()
{
	this->window = none;

	EnumWindows(enumWindowsCallback, NULL);

	return this->window;
}