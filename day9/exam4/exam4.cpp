// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


void ary_prn(int *ap)
{
	int i;
	for (int i = 0; i < 5; i++) {
		//printf("%5d \n", *(ap + i));
		printf("ary size : %d \n", sizeof(ap));
	}

	ap = ap + 1;
}

int main()
{
	int ary[5] = { 10,20,30,40,50 };
	ary_prn(ary);

	printf("%d \n", sizeof(ary));
    return 0;
}
