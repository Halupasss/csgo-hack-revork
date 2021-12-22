#include "includes.h"

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
	C_Entity lEntity(entity);

	uintptr_t boneMatrix = lEntity.getBoneMatrix();

	Vec3 vBone;

	vBone.x = *(float*)(boneMatrix + 0x30 * bone + 0xC);
	vBone.y = *(float*)(boneMatrix + 0x30 * bone + 0x1C);
	vBone.z = *(float*)(boneMatrix + 0x30 * bone + 0x2C);

	return vBone;
}

// settetrs
void C_GameEngine::setViewAngles(Vec3 angle)
{
	*(Vec3*)(CLIENTSTATE + offsets::dwClientState_ViewAngles) = angle;
}