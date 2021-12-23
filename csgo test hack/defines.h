#pragma once
#include "includes.h"

#define HACKSTATE_NORMAL true
#define HACKSTATE_OFF    false

#define null NULL
#define not !
#define and &&
#define or ||
#define is ==
#define not_is !=
#define is_not !=
#define none NULL

#define M_PI 3.14159265

#define CLIENT (uintptr_t)GetModuleHandle("client.dll")
#define ENGINE (uintptr_t)GetModuleHandle("engine.dll")
#define LOCALPLAYER *(uintptr_t*)(CLIENT + offsets::dwLocalPlayer)
#define LOCALPLAYER_ADDRESS (CLIENT + offsets::dwLocalPlayer)
#define CLIENTSTATE *(uintptr_t*)(ENGINE + offsets::dwClientState)

// keys
#define VK_ALT 18
#define VK_Q 81
#define VK_E 69