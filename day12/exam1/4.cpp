#include "stdafx.h"
#include "../../engine/utils.h"


void procTest4(HWND hWnd)
{
	int nDatas[5][6] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 5; i++) {
			nDatas[j][5] += nDatas[j][i];
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 4; i++) {
			nDatas[4][j] += nDatas[i][j];
		}
	}

	for (int a = 0; a < 5; a++) {
		win32_Printf(hWnd, L"%d %d %d %d %d %d", nDatas[a][0], nDatas[a][1], nDatas[a][2], nDatas[a][3], nDatas[a][4], nDatas[a][5]);
	}
	
}