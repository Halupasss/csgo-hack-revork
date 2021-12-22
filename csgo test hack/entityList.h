#pragma once
#include "includes.h"

#ifndef ENTITYLIST_H_
#define ENTITYLIST_H_

class C_EntityList
{
private:
	uintptr_t entity = NULL;
public:
	uintptr_t& operator[] (const int index);
};

#endif