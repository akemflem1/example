// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,4,6,7,12,54,30,29,19,39,23,19,36,2,5,3,6,7,9,0,3,19 };
	int num;

	printf("���� �Է��ϼ��� : ");
	scanf("%d", &num);
	int nCount = 0;

	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		if (num == ary[i])
			nCount++;
	}

	printf("%d \n", nCount);

    return 0;
}

