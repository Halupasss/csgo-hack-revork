#include "includes.h"

C_MenuManager::C_MenuManager()
{
	this->window = directXManager.getProcessWindow();
	this->setCustomStyle();
}

void C_MenuManager::set_pDevice(LPDIRECT3DDEVICE9 pDevice)
{
	this->pDevice = pDevice;
}

void C_MenuManager::init()
{
	ImGui::CreateContext();

	D3DDEVICE_CREATION_PARAMETERS CP;
	pDevice->GetCreationParameters(&CP);
	
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.Fonts->AddFontDefault();
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

	ImGui_ImplWin32_Init(this->window);
	ImGui_ImplDX9_Init(this->pDevice);
}