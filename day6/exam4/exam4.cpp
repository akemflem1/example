// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int odNum = 0, sum = 0;
	while (odNum <= 100) {
		if (odNum % 2 == 1) {
			sum = sum + odNum;
		}
		odNum++;
	}
	printf("1���� 100���� Ȧ�� ���� : %d", sum);
    return 0;
}

