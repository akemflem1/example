// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

void test(int**pA) {
	//int a = 7;
	//*pA = &a;
	*pA = (int *)malloc(4);
	**pA = 7;
}

void test2(int**pA) {
	int a = 11;
}

int main()
{
	int *pA;

	test(&pA);
	test2(&pA);
	printf("%d \n", *pA);
	free(pA);

    return 0;
}

