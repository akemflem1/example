#include "stdafx.h"
#include "../../engine/utils.h"

int score[3][4];

void procTest2(HWND hWnd)
{
	//첫번째 학생
	score[0][0] = 20;
	score[0][1] = 30;
	score[0][2] = 40;
	score[0][3] = 50;

	//두번째 학생
	score[1][0] = 10;
	score[1][1] = 60;
	score[1][2] = 80;
	score[1][3] = 30;

	//세번째 학생
	score[2][0] = 15;
	score[2][1] = 66;
	score[2][2] = 76;
	score[2][3] = 39;
	for (int i = 0; i < 3; i++) {
		win32_Printf(hWnd, L"%d %d %d %d", score[i][0], score[i][1], score[i][2], score[i][3]);
	}
	int totalScore[4];

		for (int i = 0; i < 4; i++) {
			totalScore[i] = 0;
			for (int j = 0; j < 3; j++) {
				totalScore[i] += score[j][i];
			}
		}
		win32_Printf(hWnd, L"%d %d %d %d", totalScore[0], totalScore[1], totalScore[2], totalScore[3]);
}