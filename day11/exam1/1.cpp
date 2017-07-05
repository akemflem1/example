#include "stdafx.h"

extern void win32_Printf(HWND hWnd, TCHAR * fmt, ...);

void test1(HWND hWnd)
{
	static int nIndex = 0;
	win32_Printf(hWnd, L"%d ¿Œµ¶Ω∫", nIndex++);
}