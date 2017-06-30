// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "string.h"


int main()
{
	char str1[10] = { 'h','e','l','l','o' };
	char str2[] = { 'h','e','l','l','o','\0' };
	char str3[] = "hello";
	char str4[16];
	
	for (int i = 0; i < strlen(str3) +1 ; i++) {
		str4[i] = str3[i];
	}
	printf("%s \n", str4);
    printf("%d \n", strlen(str3)); 
	return 0;
}

