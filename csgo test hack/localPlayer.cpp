#include "includes.h"

C_LocalPlayer::C_LocalPlayer()
{

}

// getters
uintptr_t C_LocalPlayer::getLocalPlayer()
{
	return *(uintptr_t*)(LOCALPLAYER_ADDRESS);
}

int C_LocalPlayer::getHealth()
{
	return *(int*)(LOCALPLAYER + offsets::m_iHealth);
}

int C_LocalPlayer::getArmorValue()
{
	return *(int*)(LOCALPLAYER + offsets::m_ArmorValue);
}

int C_LocalPlayer::getFlags()
{
	return *(int*)(LOCALPLAYER + offsets::m_fFlags);
}

int C_LocalPlayer::getTeamNum()
{
	return *(int*)(LOCALPLAYER + offsets::m_iTeamNum);
}

int C_LocalPlayer::getFlashDuration()
{
	return *(int*)(LOCALPLAYER + offsets::m_flFlashDuration);
}

int C_LocalPlayer::getCrosshairID()
{
	return *(int*)(LOCALPLAYER + offsets::m_iCrosshairId);
}

int C_LocalPlayer::getShotsFired()
{
	return *(int*)(LOCALPLAYER + offsets::m_iShotsFired);
}

// setters
void C_LocalPlayer::setFlag(const uintptr_t flagType, const int flag)
{
	*(int*)(CLIENT + flagType) = flag;
}

void C_LocalPlayer::nullifyFlashDuration()
{
	*(int*)(LOCALPLAYER + offsets::m_flFlashDuration) = 0;
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

// Vec3 
Vec3 C_LocalPlayer::getPosition()
{
	return *(Vec3*)(LOCALPLAYER + offsets::m_vecOrigin);
}

Vec3 C_LocalPlayer::getVelocity()
{
	return *(Vec3*)(LOCALPLAYER + offsets::m_vecVelocity);
}