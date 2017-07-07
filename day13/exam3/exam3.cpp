// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a = 1;
	double b = 3.14;

	void *pVoid;
	int *pInt;
	double *pDouble;
	
	
	pInt = &a;
	printf("%d \n", *pInt);

	pInt = (int *)&b;
	printf("%lf \n", *((double *)pInt));
	
	pVoid = &a;
	printf("%d \n", *((int *)pVoid));

	pVoid = &b;
	printf("%lf \n", *((double *)pVoid));
    return 0;
}

