#include "stdafx.h"
#include "../../engine/utils.h"


void procTest7(HWND hWnd) //����Ʈ�� �迭 ����
{
	int a = 1;
	int ary[5];
	int *ptr = &a;

	win32_Printf(hWnd, L"%u", ary);
	win32_Printf(hWnd, L"%u", &ary);

	win32_Printf(hWnd, L"%u", ary+1);
	win32_Printf(hWnd, L"%u", &ary+1); // ���� ���� �ٸ�

	win32_Printf(hWnd, L"%u", ptr);
	win32_Printf(hWnd, L"%u", &ptr);

	win32_Printf(hWnd, L"%u", ptr+1);
	win32_Printf(hWnd, L"%u", &ptr+1); //���� ���� ����
}