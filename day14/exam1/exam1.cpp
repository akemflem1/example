// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>


int main()
{
	int *pA;
	pA = (int*)malloc(4);
	*pA = 7;
	printf("%u \n", *pA);
	free(pA);
	return 0;
}

