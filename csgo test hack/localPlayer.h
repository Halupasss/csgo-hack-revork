#pragma once
#include "includes.h"

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
	int getShotsFired();
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