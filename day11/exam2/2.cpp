#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

char *getBuf1()
{
	char buf[5];
	return buf;
}

char *getBuf2()
{
	char buf[5];
	return buf;
}

void testProc2(HWND hWnd)
{
	char *ptr = getBuf1();
	ptr[0] = '1';
	ptr[1] = '2';
	ptr[2] = '3';
	ptr[3] = '4';
	ptr[4] = '5';

	win32_Printf(hWnd, L"%d", ptr[0]);

	ptr = getBuf2(); //이전에 사용하던 스택의 영역이 다시 리셋된다.

	win32_Printf(hWnd, L"%d", ptr[0]);

}