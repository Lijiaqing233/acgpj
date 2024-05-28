#include "Main.h"
#include "iostream"
#include "DirectXMath.h"
#include "d3dcompiler.h"
#include "d3d12.h"

#include "AcgWindows.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, 
                    int nCmdShow)
{
	auto acgWindows = new AcgWindows("jj");
	acgWindows->CreateWindowsClass(hInstance);
}
