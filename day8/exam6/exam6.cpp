// exam6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int test1 = 100;
	int *pTest1;

	pTest1 = &test1;
	printf("%d %d \n", pTest1, *pTest1);
    
	test1 = 200;
	printf("%d \n", *pTest1);

	int a;
	int *ap = &a;
	a = 100;
	printf("%d , %d \n", a, *ap);

	a = 300;
	printf("%d , %d \n", a, *ap);

	*ap = 500;
	printf("%d , %d \n", a, *ap);

	int b1, b2;
	b1 = 1;
	b2 = b1;
	printf("%d , %d \n", b1, b2);
	b2 = 2;
	printf("%d , %d \n", b1, b2);
	return 0;
}

