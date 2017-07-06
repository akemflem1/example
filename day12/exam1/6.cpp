#include "stdafx.h"
#include "../../engine/utils.h"

void swapString(TCHAR **str1, TCHAR **str2)
{
	TCHAR *szTemp;
	szTemp = *str2;
	*str2 = *str1;
	*str1 = szTemp;
}

void print_ary(HWND hWnd, TCHAR **pAry, int nCount)
{
	int i;
	for (i = 0; i < nCount; i++) {
		win32_Printf(hWnd, L"%s", *(pAry+i));
	}
}

void procTest6(HWND hWnd)
{
	int val = 100;
	int *ip = &val;
	int **ipp = &ip;
	int ***ippp = &ipp;

	win32_Printf(hWnd, L"%d %d", ip,*ipp);
	win32_Printf(hWnd, L"%d %d %d",val, *ip, **ipp);

	win32_Printf(hWnd, L"%d %d", ip, ipp);
	win32_Printf(hWnd, L"%d %d %d", *ippp, **ippp , ***ippp);
	
	TCHAR *szStr[2] = { L"�ȳ��ϼ���.",L"���� ����� �Դϴ�." };
	/*TCHAR *szTemp;
	szTemp = szStr[0];
	szStr[0] = szStr[1];
	szStr[1] = szTemp;*/
	swapString(&szStr[0], &szStr[1]);

	win32_Printf(hWnd, L"%s %s", szStr[0] , szStr[1]);

	TCHAR *ptr_ary[] = { L"����",L"��",L"Ƽ���",L"������",L"�Ƹ�������" };
	print_ary(hWnd,ptr_ary,sizeof(ptr_ary)/sizeof(ptr_ary[0]));		
	
}

