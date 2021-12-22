#include "includes.h"

#define is ==
#define and &&
#define or ||
#define none NULL

C_Entity::C_Entity(uintptr_t _entity)
{
	this->entity = _entity;
}

int C_Entity::getHealth()
{
	if (this->entity is none)
		return NULL;

	return *(int*)(this->entity + offsets::m_iHealth);
}

int C_Entity::getTeamNum()
{
	if (this->entity is none)
		return NULL;

	return *(int*)(this->entity + offsets::m_iTeamNum);
}

int C_Entity::getArmorValue()
{
	if (this->entity is none)
		return NULL;

	return *(int*)(this->entity + offsets::m_ArmorValue);
}

int C_Entity::getGlowIndex()
{
	if (this->entity is none)
		return NULL;

	return *(int*)(this->entity + offsets::m_iGlowIndex);
}

uintptr_t C_Entity::getBoneMatrix()
{
	if (this->entity is none)
		return NULL;

	return *(uintptr_t*)(this->entity + offsets::m_dwBoneMatrix);
}

// chekers
bool C_Entity::isAlive()
{
	int health = this->getHealth();

	return health >= NULL;
}

bool C_Entity::isSpottedByMask()
{
	if (this->entity is none)
		return NULL;

	return *(int*)(this->entity + offsets::m_bSpottedByMask);
}