#include "stdafx.h"
#include "../../engine/utils.h"


void procTest5(HWND hWnd)
{
	//TCHAR animal[][20] = { L"����",L"�����", L"ȣ����", L"����", L"�ݴް�" };

	TCHAR *animal[5] = { L"����",L"�����", L"ȣ����", L"����", L"�ݴް�" };

	for (int i = 0; i < 5; i++) {
		win32_Printf(hWnd, L"%s", animal[i]);
	}

	win32_Printf(hWnd, L"%s", *(animal+2));
	win32_Printf(hWnd, L"%c", *(*(animal + 4) + 2));
	win32_Printf(hWnd, L"%c", animal[4][2]);
}