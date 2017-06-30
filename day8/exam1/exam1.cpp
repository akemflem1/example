// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[50];
	
	word[0] = 'L';
	word[1] = 'o';
	word[2] = 'v';
	word[3] = 'e';
	word[4] = '\0';

	printf("%s \n", word);

	//word[0] = '사';
	//word[1] = '랑';

	TCHAR word2[50];
	word2[0] = L'사';
	word2[1] = L'랑';
	word2[2] = L'\0';
	word2[3] = L'a';
	
	printf("char size : %d  TCHAR size : %d \n", sizeof(char), sizeof(TCHAR));
	//swprintf(L"%s \n", word2);
	return 0;
}

