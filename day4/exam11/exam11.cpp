// exam11.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char backNum;
	int	Age;
	double batAve;

	printf("���ȣ�� �Է��ϼ��� : ");
	scanf("%c", &backNum);
	printf("Ÿ���� �Է��ϼ��� : ");
	scanf("%lf", &batAve);
	printf("���̸� �Է��ϼ��� : ");
	scanf("%d", &Age);

	printf("%c�� ������ Ÿ���� %lf�̰� ���̴� %d���Դϴ�. \n", backNum, batAve, Age);

    return 0;
}

