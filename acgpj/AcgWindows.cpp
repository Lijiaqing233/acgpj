#include "AcgWindows.h"



AcgWindows::AcgWindows(std::string className)
{
	
}

AcgWindows::~AcgWindows()
{

}

int AcgWindows::CreateWindowsClass(HINSTANCE hInstance)
{
	std::string className = "MyWindowsClass";
	WNDCLASSEX windowsClass = { 0 };
	windowsClass.cbSize = sizeof(WNDCLASSEX);
	windowsClass.lpszClassName = className.c_str();
	windowsClass.lpfnWndProc = MessageProc;
	windowsClass.hInstance = hInstance;
	windowsClass.hbrBackground = CreateSolidBrush(RGB(0.7, 0.7, 0.7));
	windowsClass.hCursor = LoadCursor(nullptr, IDC_ARROW);

	auto registerClass = RegisterClassEx(&windowsClass);

	if (registerClass == 0)
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

	if (hwnd == 0)
	{
		GetLastError();
		return -1;
	}
	ShowWindow(hwnd, SW_SHOW);

	MSG msg;
	while (GetMessage(&msg, nullptr, NULL, NULL) != 0)
	{
		DispatchMessage(&msg);
	}
	return 0;

}

LRESULT CALLBACK AcgWindows::MessageProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
		OutputDebugString("windows is created!");
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_PRINT:
		OutputDebugString("windows need repaint!");
		break;
	default: break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}
