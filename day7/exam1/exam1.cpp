// exam1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	int avg = 0;
	int max = 0;
	int min = 500;

	for (int i = 0; i < 5; i++) {
		printf("%d��° �����͸� �Է��ϼ��� : ", i);
		scanf("%d",&ages[i]);
	}

	for (int i = 0; i < 5; i++) {
		avg += ages[i];
	}
	avg /= 5;

	printf("��� : %d \n", avg);

	for (int i = 0; i < 5; i++) {
		if (max < ages[i])
			max = ages[i];
	}
		printf("�ִ밪 : %d \n", max);

	for (int i = 0; i < 5; i++) {
		if (min > ages[i])
			min = ages[i];
	}
		printf("�ּҰ� : %d \n", min);
    return 0;
}

