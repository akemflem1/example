// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int test1;
	char test2;
	char test3;
	int test4;
	int test5;
	char test6;
	char test7;

	test1 = 0x11223344;
	test2 = 0x55;

	printf("%d \n", ((unsigned long)&test1) - (unsigned long)&test2);
	printf("%d \n", ((unsigned long)&test2) - (unsigned long)&test3);
	printf("%d \n", ((unsigned long)&test3) - (unsigned long)&test4);
	printf("%d \n", ((unsigned long)&test4) - (unsigned long)&test5);
	printf("%d \n", ((unsigned long)&test5) - (unsigned long)&test6);
	printf("%d \n", ((unsigned long)&test6) - (unsigned long)&test7);

    return 0;
}

