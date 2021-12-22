#include "includes.h"

C_LocalPlayer::C_LocalPlayer()
{
	this->pLocalPlayer = (uintptr_t*)(CLIENT + offsets::dwLocalPlayer);
	this->pHealth	   = (uintptr_t*)(LOCALPLAYER + offsets::m_iHealth);
	this->pArmor	   = (uintptr_t*)(LOCALPLAYER + offsets::m_ArmorValue);
	this->pFlags	   = (uintptr_t*)(LOCALPLAYER + offsets::m_fFlags);
}

// getters
uintptr_t C_LocalPlayer::getLocalPlayer()
{
	return *(uintptr_t*)this->pLocalPlayer;
}

int C_LocalPlayer::getHealth()
{
	return *(int*)this->pHealth;
}

int C_LocalPlayer::getArmor()
{
	return *(int*)this->pArmor;
}

int C_LocalPlayer::getFlags()
{
	return *(int*)this->pFlags;
}

// setters
void C_LocalPlayer::setFlag(const uintptr_t flagType, const int flag)
{
	*(int*)(CLIENT + flagType) = flag;
}

// methods
void C_LocalPlayer::jump()
{
	this->setFlag(offsets::dwForceJump, cVars::flags::fOn);
	Sleep(cVars::bhop::vBhopDelay);
	this->setFlag(offsets::dwForceJump, cVars::flags::fOff);
}

void C_LocalPlayer::shoot()
{
	this->setFlag(offsets::dwForceAttack, cVars::flags::fOn);
	Sleep(settings::aimbot::vDelay);
	this->setFlag(offsets::dwForceAttack, cVars::flags::fOff);
}

// chekers
bool C_LocalPlayer::isAlive()
{
	int health = this->getHealth();

	return health >= 0;
}