// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

