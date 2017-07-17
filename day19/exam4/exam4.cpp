// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <comdef.h>

int main()
{
	//wchar -> char
	TCHAR *strMsgW = L"안녕하세요";

	_bstr_t convObj(strMsgW);

	char *strMsgW_cnv = (char *)convObj;

	printf("%s \n", strMsgW_cnv);

	//char ->wchar
	char *strMsgC = "반갑습니다";
	TCHAR szBufW[256];

	mbstowcs(szBufW, strMsgC, 256);
	
	wprintf(L"%s \n", szBufW);

	return 0;
}

