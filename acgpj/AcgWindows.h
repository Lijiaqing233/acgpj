#pragma once

#include "Windows.h"
#include "iostream"

class AcgWindows
{
public:
	AcgWindows(std::string className);
	~AcgWindows();

	int CreateWindowsClass(HINSTANCE hInstance);

private:
	WNDCLASSEX m_windowsClass;
	std::string m_className;
	HWND m_hwnd;

	static LRESULT CALLBACK MessageProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
};
