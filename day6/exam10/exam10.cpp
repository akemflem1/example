// exam10.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void printSum(int a, int b)
{
	int sum = a + b;
	printf("sum : %d \n", sum);
}

int getSum(int a, int b)
{
	return a+b;
}

int main()
{
	int a, b, sum;

	scanf("%d %d", &a, &b);
	printSum(a, b);

	sum = getSum(a, b);
	printf("%d \n", sum);

    return 0;
}

