#include "includes.h"

uintptr_t& C_EntityList::operator[] (const int index)
{
	uintptr_t entity = *(uintptr_t*)(CLIENT + offsets::dwEntityList + index * cVars::memory::playerStructureSize);

	this->entity = entity;

	return entity;
}