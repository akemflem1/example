#include "stdafx.h"

extern void win32_Printf(HWND hWnd, TCHAR * fmt, ...);

int sum(int a, int b)
{
	return a + b;
}

void testProc2(HWND hWnd)
{
	win32_Printf(hWnd, L"test proc2");

	int a, b;

	a = 2; b = 3;

	win32_Printf(hWnd, L"sum : %d",sum (a,b));
}