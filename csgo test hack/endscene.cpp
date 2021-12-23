#include "includes.h"

#define WINDOW_NAME "Hack"
typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
EndScene oEndScene = NULL;
WNDPROC oWndProc = NULL;
C_DirectXManager directXManager;
static C_MenuManager menuManager;


HRESULT __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (not MainApplication.imGuiInit)
	{
		menuManager.set_pDevice(pDevice);
		directXManager.set_pDevice(pDevice);

		MainApplication.imGuiInit = true;
	}

	if (MainApplication.menuActive is true)
		menuManager.draw();

	return oEndScene(pDevice);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ImGuiIO& io = ImGui::GetIO();

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

uintptr_t __stdcall hack::kieroInit(HMODULE hModule)
{
	bool attached = false;
	HWND window = none;

	do
	{
		if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success)
		{
			kiero::bind(42, (void**)&oEndScene, hkEndScene);

			do {
				window = directXManager.getProcessWindow();
			} while (window == NULL);

			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
			attached = true;
		}
	} while (!attached);

	return TRUE;
}