#pragma once
#include "includes.h"

class C_Entity
{
private:
	uintptr_t entity = NULL;
public:
	// methods
	void detect();
public:
	// getters
	int getHealth();
	int getTeamNum();
	int getArmorValue();
	int getGlowIndex();
	uintptr_t getBoneMatrix();
public:
	// chekers
	bool isAlive();
	bool isSpottedByMask();
public:
	C_Entity(uintptr_t _entity);
};