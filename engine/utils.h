#pragma once

extern void win32_Printf(HWND hWnd, TCHAR *fmt, ...);
extern void DisplayLog(HDC hdc);
void win32_Scanf(const TCHAR *szBuf, const TCHAR *fmt, ...);// scanf나 printf는 뒤에 인수가 많이오기때문에 ...을 넣어 여유공간을 확보해준다.