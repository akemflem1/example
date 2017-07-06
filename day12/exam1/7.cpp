#include "stdafx.h"
#include "../../engine/utils.h"


void procTest7(HWND hWnd) //포인트와 배열 차이
{
	int a = 1;
	int ary[5];
	int *ptr = &a;

	win32_Printf(hWnd, L"%u", ary);
	win32_Printf(hWnd, L"%u", &ary);

	win32_Printf(hWnd, L"%u", ary+1);
	win32_Printf(hWnd, L"%u", &ary+1); // 증가 폭이 다름

	win32_Printf(hWnd, L"%u", ptr);
	win32_Printf(hWnd, L"%u", &ptr);

	win32_Printf(hWnd, L"%u", ptr+1);
	win32_Printf(hWnd, L"%u", &ptr+1); //증가 폭이 같음
}