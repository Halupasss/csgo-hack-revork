#pragma once
#include "includes.h"

#ifndef DIRECTXMANAGER_H_
#define DIRECTXMANAGER_H_

class C_DirectXManager
{
private:
	HWND window;
	LPDIRECT3DDEVICE9 pDevice;
public:
	HWND getProcessWindow();
public:
	void set_pDevice(LPDIRECT3DDEVICE9 pDevice);
};

extern C_DirectXManager directXManager;

#endif