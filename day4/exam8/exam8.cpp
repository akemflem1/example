// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num,num2;

	printf("정수값을 입력하세요 : ");
	scanf("%d %d", &num, &num2);

	printf("%d, %d 을 입력하셨습니다. \n", num,num2);
	printf("두수의 합은 %d 입니다. \n", num + num2);
    return 0;
}

