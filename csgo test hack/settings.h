#pragma once

namespace settings
{
	namespace fun
	{
		namespace qe
		{
			extern int maxAngle;
			extern int minAngle;
			extern size_t leftKey;
			extern size_t rightKey;
		}
	}
	namespace keys
	{
		extern size_t jumpButton;
		extern size_t endButton;
		extern size_t aimBotKey;
	}
	namespace modules
	{
		extern bool bhop;
		extern bool neonGlow;
		extern bool noFlash;
		extern bool aimBot;
		extern bool radarHack;
		extern bool recoilControlSystem;
		extern bool triggerBot;
	}
	namespace triggerBot
	{
		extern size_t delay;
	}
	namespace aimbot
	{
		extern size_t vDelay;
		extern size_t targetBone;
		extern bool aimTroughWalls;
	}
	namespace neonGlow
	{
		namespace myTeam
		{
			extern float alpha;
			extern float color[3];
		}
		namespace entityTeam
		{
			extern float alpha;
			extern float color[3];
		}
	}
}
