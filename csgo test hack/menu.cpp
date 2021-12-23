#include "includes.h"

static bool imGuiIsOpen = true;
static int currentTab = 0;

static class tabs
{
public:
	int modules = 0;
	int colors = 1;
	int wallhack = 2;
	int aimbot = 3;
	int skinchanger = 4;
} Tabs;

void C_MenuManager::draw()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Settings", &imGuiIsOpen, ImGuiWindowFlags_NoTitleBar);
	ImGui::SetWindowSize(ImVec2(750, 650));
	/* draw here  */
	/* tabs       */

	if (ImGui::Button("modules", ImVec2(150, 30))) {
		currentTab = Tabs.modules;
	}
	if (ImGui::Button("colors", ImVec2(150, 30))) {
		currentTab = Tabs.colors;
	}
	if (ImGui::Button("wallhack", ImVec2(150, 30))) {
		currentTab = Tabs.wallhack;
	}
	if (ImGui::Button("aimbot", ImVec2(150, 30))) {
		currentTab = Tabs.aimbot;
	}
	if (ImGui::Button("skinchanger", ImVec2(150, 30))) {
		currentTab = Tabs.skinchanger;
	}

	/* menu        */
	if (currentTab is Tabs.modules)
	{
		/*
			aimbot:    radiobutton
			bhop:      radiobutton
			neonglow:  radiobutton
			noflash:   radiobutton
			radarhack: radiobutton
			rcssystem: radiobutton
			triggerbot:radiobutton
		*/

		if (ImGui::RadioButton("aimbot", settings::modules::aimBot))
			settings::modules::aimBot = !settings::modules::aimBot;

		if (ImGui::RadioButton("bhop", settings::modules::bhop))
			settings::modules::bhop = !settings::modules::bhop;

		if (ImGui::RadioButton("neonglow", settings::modules::neonGlow))
			settings::modules::neonGlow = !settings::modules::neonGlow;

		if (ImGui::RadioButton("noflash", settings::modules::noFlash))
			settings::modules::noFlash = !settings::modules::noFlash;

		if (ImGui::RadioButton("radarhack", settings::modules::radarHack))
			settings::modules::radarHack = !settings::modules::radarHack;

		if (ImGui::RadioButton("rcs", settings::modules::recoilControlSystem))
			settings::modules::recoilControlSystem = !settings::modules::recoilControlSystem;

		if (ImGui::RadioButton("triggerbot", settings::modules::triggerBot))
			settings::modules::triggerBot = !settings::modules::triggerBot;
	}
	ImGui::End();

	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}