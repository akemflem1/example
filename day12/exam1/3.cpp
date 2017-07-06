#include "stdafx.h"
#include "../../engine/utils.h"


void procTest3(HWND hWnd)
{
	int nums_1[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int nums_2[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	int nums_3[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	win32_Printf(hWnd, L"[0,0] : %d %d", nums_1[0][0],nums_2[0][0]);
	win32_Printf(hWnd, L"[1,0] : %d %d", nums_1[1][0], nums_2[1][0]);
	
	int col = 0;
	int row = 1;

	win32_Printf(hWnd, L"[1,0] : %d %d", nums_1[row][col], nums_2[row][col]);
	win32_Printf(hWnd, L"[1,0] : %d %d", nums_3[4 * row + col], nums_3[6 * row + col]);
}