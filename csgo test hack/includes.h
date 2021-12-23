#pragma once

#include "kiero/kiero.h"
#include "dear_imgui/imgui.h"
#include "dear_imgui/imgui_internal.h"
#include "dear_imgui/imgui_impl_dx9.h"
#include "dear_imgui/imgui_impl_win32.h"
#include "kiero/minhook/include/MinHook.h"

#include <iostream>
#include <windows.h>
#include <string>

#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")

/* my shit */
#include "defines.h"
#include "mainApplication.h"
#include "vector3.h"
#include "constVars.h"
#include "entityList.h"
#include "entity.h"
#include "engine.h"
#include "localPlayer.h"
#include "menuManager.h"
#include "directxManager.h"
#include "settings.h"

#include "offsets.hpp"