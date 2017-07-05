#include "stdafx.h"

extern void win32_Printf(HWND hWnd, TCHAR * fmt, ...);

int test() 
{
	int a = 5;
	int b = 6;

	return a, b;
}

void testProc3(HWND hWnd)
{
	int a = 1, b = 1;
	{
		int a = 1, b = 2;
		{
			win32_Printf(hWnd, L"%d %d", a, b);
			int a = 3;
			int b = 4;
			win32_Printf(hWnd, L"%d %d", a, b);
		}
		win32_Printf(hWnd, L"%d %d", a, b);
	}
	test();
	win32_Printf(hWnd, L"%d %d", a, b);
}