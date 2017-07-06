#include "stdafx.h"
#include "../../engine/utils.h"


void procTest5(HWND hWnd)
{
	//TCHAR animal[][20] = { L"사자",L"고양이", L"호랑이", L"여우", L"반달곰" };

	TCHAR *animal[5] = { L"사자",L"고양이", L"호랑이", L"여우", L"반달곰" };

	for (int i = 0; i < 5; i++) {
		win32_Printf(hWnd, L"%s", animal[i]);
	}

	win32_Printf(hWnd, L"%s", *(animal+2));
	win32_Printf(hWnd, L"%c", *(*(animal + 4) + 2));
	win32_Printf(hWnd, L"%c", animal[4][2]);
}