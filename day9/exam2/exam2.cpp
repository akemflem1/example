// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double ary[] = { 1.5,20.1,16.4,2.3,3.5 };
	double *ap = ary;
	double sum = 0;

	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		//sum += *(ary + i);
		sum += *(ap + i);
	}

	printf("%.2lf \n", sum/ (sizeof(ary) / sizeof(ary[0])));

    return 0;
}

