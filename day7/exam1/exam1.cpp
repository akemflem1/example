// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	int avg = 0;
	int max = 0;
	int min = 500;

	for (int i = 0; i < 5; i++) {
		printf("%d번째 데이터를 입력하세요 : ", i);
		scanf("%d",&ages[i]);
	}

	for (int i = 0; i < 5; i++) {
		avg += ages[i];
	}
	avg /= 5;

	printf("평균 : %d \n", avg);

	for (int i = 0; i < 5; i++) {
		if (max < ages[i])
			max = ages[i];
	}
		printf("최대값 : %d \n", max);

	for (int i = 0; i < 5; i++) {
		if (min > ages[i])
			min = ages[i];
	}
		printf("최소값 : %d \n", min);
    return 0;
}

