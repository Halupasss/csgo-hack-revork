#pragma once
#include "constVars.h"

/* const vars */

// bhop
size_t cVars::bhop::vBhopDelay = 17;

// flags
size_t cVars::flags::fOn = 5;
size_t cVars::flags::fOff = 4;
size_t cVars::flags::fOnGround = 257;

// memory
size_t cVars::memory::playerStructureSize = 0x10;

// game
size_t cVars::game::maxNumOfPlayersInServer = 64;
size_t cVars::game::meIndex = 1;
size_t cVars::game::headBone = 8;
size_t cVars::game::aimPunchAngleCoefficient = 2;

/* settings   */

// keys
size_t settings::keys::endButton = VK_END;
size_t settings::keys::jumpButton = VK_SPACE;
size_t settings::keys::aimBotKey = VK_ALT;
size_t settings::keys::menuKey = VK_HOME;

// modules
bool settings::modules::bhop = false;
bool settings::modules::neonGlow = false;
bool settings::modules::noFlash = false;
bool settings::modules::aimBot = false;
bool settings::modules::radarHack = false;
bool settings::modules::recoilControlSystem = false;
bool settings::modules::triggerBot = false;

// trigger bot
size_t settings::triggerBot::delay = 65;

// aimbot
size_t settings::aimbot::vDelay = 50;
size_t settings::aimbot::targetBone = cVars::game::headBone;
bool settings::aimbot::aimTroughWalls = false;

// neonglow

// my team
float settings::neonGlow::myTeam::alpha = 1;
float settings::neonGlow::myTeam::color[3] = { 0, 1, 1 };
// entity team
float settings::neonGlow::entityTeam::alpha = 1.7;
float settings::neonGlow::entityTeam::color[3] = { 1, 0, 1 };

// fun

// qe
int settings::fun::qe::maxAngle = 25;
int settings::fun::qe::minAngle = -25;
size_t settings::fun::qe::leftKey = VK_Q;
size_t settings::fun::qe::rightKey = VK_E;