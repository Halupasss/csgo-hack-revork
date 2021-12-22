#pragma once

namespace settings
{
	namespace keys
	{
		extern size_t jumpButton;
		extern size_t endButton;
	}
	namespace modules
	{
		extern bool bhop;
		extern bool neonGlow;
		extern bool noFlash;
		extern bool aimBot;
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
