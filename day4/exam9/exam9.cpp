// exam9.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double tax, pi=3.14;

	printf("%lf \n", pi);

	printf("세금을 입력하세요 : ");
	scanf("%lf", &tax);
	printf("세금은 : %lf 입니다. \n", tax);

	float num;
	printf("아무실수나 입력하세요 : ");
	scanf("%f", &num);
	printf("%f을 입력하셨습니다. \n", num);
    return 0;
}

