#pragma once
#include "includes.h"

#ifndef MENUMANAGER_H_
#define MENUMANAGER_H_

class C_MenuManager
{
private:
	HWND window;
	LPDIRECT3DDEVICE9 pDevice;
private:
	void init();
	void setCustomStyle();
public:
	void draw();
public:
	void set_pDevice(LPDIRECT3DDEVICE9 pDevice);
public:
	// init
	C_MenuManager();
};
#endif