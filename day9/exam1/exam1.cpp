// exam1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	//short ary[5] = { 10,20,30,40,50 };
	//char ary[5] = { 10,20,30,40,50 };
	int ary[5] = { 10,20,30,40,50 };
	int *ap = ary;


	printf("%u : %d \n", ary, ary[0]);
	printf("%u : %d \n", &ary[1], ary[1]);
	printf("%u : %d \n", &ary[0] + 1, *(&ary[0] + 1));
	printf("%u : %d \n", &ary[0] + 4, ary[4]);

	printf("%u : %d \n", ap + 4, *(ap + 4));

	return 0;
}

