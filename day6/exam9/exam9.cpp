// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int i = 0;
	while (true) {
		i++;
		if (i > 10){
			break;
		}
		printf("count : %d \n", i);
	}


	i = 0;
	while (true) {
		i++;
		if (i > 10) {
			break;
		}
		if (i % 2) {
			continue;
		}
		printf("count : %d \n", i);
	}
    return 0;
}

