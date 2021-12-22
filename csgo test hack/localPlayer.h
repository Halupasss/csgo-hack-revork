#pragma once
#include "includes.h"

#define CLIENT (uintptr_t)GetModuleHandle("client.dll")
#define ENGINE (uintptr_t)GetModuleHandle("engine.dll")
#define LOCALPLAYER *(uintptr_t*)(CLIENT + offsets::dwLocalPlayer)
#define LOCALPLAYER_ADDRESS (CLIENT + offsets::dwLocalPlayer)
#define CLIENTSTATE *(uintptr_t*)(ENGINE + offsets::dwClientState)

#ifndef LOCALPLAYER_H_
#define LOCALPLAYER_H_

class C_LocalPlayer
{
public:
	// getters
	uintptr_t getLocalPlayer();
	int getHealth();
	int getArmorValue();
	int getFlags();
	int getTeamNum();
	int getFlashDuration();
	int getCrosshairID();
public:
	// setters
	void setFlag(const uintptr_t flagType, const int flag);
public:
	// methods
	void jump();
	void shoot();
	void nullifyFlashDuration();
public: /* data type: Vector3 */
	Vec3 getPosition();
public:
	// chekers
	bool isAlive();
public:
	C_LocalPlayer();
};

#endif