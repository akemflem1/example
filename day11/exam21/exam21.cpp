// exam21.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//int *add_ten(int); 함수를 먼저 써주거나, 나중에 사용할땐 선언을 먼저 해준다.
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



