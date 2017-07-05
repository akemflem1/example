#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);
int addTen(int b)
{
	b += 10;
	return b;
}

void addTen2(int *b)
{
	*b += 10;
}

void addTen3(int &b) //참조형
{
	b += 10;
}

int *addTen4(int b)
{
	b += 10;
	return &b;
}

void testProc1(HWND hWnd)
{
	win32_Printf(hWnd, L"testproc1");

	int a, c;
	a = 5;
	c = addTen(a);

	win32_Printf(hWnd, L"%d", c);

	addTen2(&c);

	win32_Printf(hWnd, L"%d", c);

	addTen3(c);

	win32_Printf(hWnd, L"%d", c);

	int *ap = addTen4(c);  // 없어진 주소값에 대해서 사용하기 때문에 위험성이 있음

	win32_Printf(hWnd, L"%d", *ap);
}