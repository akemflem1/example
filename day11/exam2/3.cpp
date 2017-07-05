#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

void testProc3(HWND hWnd)
{
	static int nCount = 0; // static을 사용하여 한번 선언되고 끝, 대신 스택밖으로 나가면 사용할수 없음
	double ary[] = { 0.1,0.3,0.5,0.7,0.9 };

	win32_Printf(hWnd, L"%lf", ary[nCount%5]);
	nCount++;
}