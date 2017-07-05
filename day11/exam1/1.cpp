#include "stdafx.h"

extern void win32_Printf(HWND hWnd, TCHAR * fmt, ...);

void test1(HWND hWnd)
{
	static int nIndex = 0;
	win32_Printf(hWnd, L"%d 인덱스", nIndex++);
}

void input()
{
	int a, b;
	a = 1;
	b = 2;
}

void test2(HWND hWnd)
{
	int a, b;
	a = 3; b = 4;
	input();

	win32_Printf(hWnd, L"%d %d", a , b);

	{
		//int a, b; //자동변수 생성
		a = 11; b = 12;
		win32_Printf(hWnd, L"%d %d", a, b);
	}
	win32_Printf(hWnd, L"%d %d", a, b);

	a = 3; b = 4;
	{
		int a, b; //자동변수 생성
		a = 11; b = 12; //지역적으로 유효한 자동변수에 값을 대입
		win32_Printf(hWnd, L"%d %d", a, b);
	}

	win32_Printf(hWnd, L"%d %d", a, b);

}