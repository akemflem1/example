// exam21.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//int *add_ten(int); �Լ��� ���� ���ְų�, ���߿� ����Ҷ� ������ ���� ���ش�.
int *add_ten(int b)
{
	b += 10;
	return &b;
}

int main()
{
	int a = 10;
	int *ap;

	ap = add_ten(a);
	printf("a : %d \n", *ap);

    return 0;
}



