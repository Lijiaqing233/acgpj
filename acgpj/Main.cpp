#include "Main.h"
#include "Windows.h"
#include "iostream"
#include "DirectXMath.h"
#include "d3dcompiler.h"
#include "d3d12.h"

int CreateWindowsClass(HINSTANCE hInstance)
{
	std::string className = "MyWindowsClass";
	WNDCLASSEX windowsClass = {0};
	windowsClass.cbSize = sizeof(WNDCLASSEX);
	windowsClass.lpszClassName = className.c_str();
	windowsClass.lpfnWndProc = DefWindowProc;
	windowsClass.hInstance = hInstance;

	auto registerClass = RegisterClassEx(&windowsClass);

	if(registerClass == 0)
	{
		GetLastError();
		return -1;
	}

	HWND hwnd = CreateWindowEx(NULL,
		className.c_str(),
		"AcgEngine",
		WS_OVERLAPPEDWINDOW,
		100,
		200,
		800,
		600,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	if(hwnd == 0)
	{
		GetLastError();
		return -1;
	}
	ShowWindow(hwnd, SW_SHOW);

	while (true)
	{


	}
	return 0;

}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, 
                    int nCmdShow)
{

	CreateWindowsClass(hInstance);
}
