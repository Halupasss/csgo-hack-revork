#pragma once
#include "includes.h"

#define CLIENT (uintptr_t)GetModuleHandle("client.dll")
#define ENGINE (uintptr_t)GetModuleHandle("engine.dll")
#define LOCALPLAYER (uintptr_t*)(CLIENT + offsets::dwLocalPlayer)

class C_LocalPlayer
{
private:
	// pointers
	uintptr_t* pLocalPlayer;
	uintptr_t* pHealth;
	uintptr_t* pArmor;
	uintptr_t* pFlags;
public:
	// getters
	uintptr_t getLocalPlayer();
	int getHealth();
	int getArmor();
	int getFlags();
public:
	// setters
	void setFlag(const uintptr_t flagType, const int flag);
public:
	// methods
	void jump();
	void shoot();
public:
	// chekers
	bool isAlive();
public:
	C_LocalPlayer();
};