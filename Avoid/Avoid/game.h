#pragma once







extern void OnLoop(double fDelta);
extern void OnRender(double fDelta, Graphics *pGrp);
extern void OnCreate(HWND hWnd);
extern void OnDestroy(HWND hWnd);
extern BYTE keyStatus[256];
extern player body;