// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int odNum = 0, sum = 0;
	while (odNum <= 100) {
		if (odNum % 2 == 1) {
			sum = sum + odNum;
		}
		odNum++;
	}
	printf("1부터 100까지 홀수 합은 : %d", sum);
    return 0;
}

