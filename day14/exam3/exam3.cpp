// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	int *ip;
	
	ip = (int *)malloc(5 * sizeof(int));

	ip[0] = 23;
	ip[1] = 24;
	ip[2] = 21;
	ip[3] = 25;
	ip[4] = 31;

	double avr = 0;
	for (int i = 0; i < 5; i++) {
		avr += ip[i];
	}

	printf("%lf \n", avr/5);
    return 0;
}

