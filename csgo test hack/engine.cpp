#include "includes.h"

#define is ==
#define not !
#define and &&
#define none 0

// getters
uintptr_t C_GameEngine::getGlowManager()
{
	return *(uintptr_t*)(CLIENT + offsets::dwGlowObjectManager);
}

// getters (data type: Vector3)
Vec3 C_GameEngine::getMyViewAngles()
{
	return *(Vec3*)(CLIENTSTATE + offsets::dwClientState_ViewAngles);
}

Vec3 C_GameEngine::getBonePos(uintptr_t& entity, const int bone)
{
	uintptr_t boneMatrix = this->getBoneMatrix(entity);

	Vec3 vBone;

	vBone.x = *(float*)(boneMatrix + 0x30 * bone + 0xC);
	vBone.y = *(float*)(boneMatrix + 0x30 * bone + 0x1C);
	vBone.z = *(float*)(boneMatrix + 0x30 * bone + 0x2C);

	return vBone;
}

uintptr_t C_GameEngine::getBoneMatrix(uintptr_t &entity)
{
	if (entity is none)
		return NULL;

	return *(uintptr_t*)(entity + offsets::m_dwBoneMatrix);
}

// settetrs
void C_GameEngine::setViewAngles(Vec3 angle)
{
	if (angle.x != NULL)
		*(float*)(CLIENTSTATE + offsets::dwClientState_ViewAngles) = angle.x;

	if (angle.y != NULL)
		*(float*)(CLIENTSTATE + offsets::dwClientState_ViewAngles + 0x4) = angle.y;

	*(float*)(CLIENTSTATE + offsets::dwClientState_ViewAngles + 0x8) = angle.z;
}