#pragma once

void makeMiniEditBox(HWND hWnd, int nPosX, int nPosY, int nHandle)
{
	CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
}

void makeSimpleButton(HWND hWnd, TCHAR *pszText, int nPosX, int nPosY, int nHandle)
{
	CreateWindow(L"button", pszText, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
}