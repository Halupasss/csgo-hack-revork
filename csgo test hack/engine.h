#pragma once
#include "includes.h"

#ifndef ENGINE_H_
#define ENGINE_H_

class C_GameEngine
{
public:
	// getters
	uintptr_t getGlowManager();
public:
	// setters
	void setViewAngles(Vec3 angle);
public: /* getters(data type : Vector3) */ 
	Vec3 getMyViewAngles();
	Vec3 getBonePos(uintptr_t &entity, const int bone);
};

#endif