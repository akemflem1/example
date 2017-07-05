#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

int a;

void test1()
{
	//static int a;
	a = 3;
}

void testProc4(HWND hWnd)
{
	a = 1;
	win32_Printf(hWnd, L"%d", a);

	test1();
	win32_Printf(hWnd, L"%d", a);
}