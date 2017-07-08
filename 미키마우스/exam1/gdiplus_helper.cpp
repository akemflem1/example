#include "stdafx.h"
#include "Resource.h"
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

DWORD g_dwGdiLoopFsm = 0;

void StartGDILoop()
{
	g_dwGdiLoopFsm = 10;
}

void StopGDILoop()
{
	g_dwGdiLoopFsm = 20;
}

void Test_DrawPath(Graphics* graphBackBuffer, void * pParam)
{
	
	Pen *pen = *(Pen **)pParam;
	//패스 그리기

	graphBackBuffer->DrawArc(pen, Rect(50, 50, 50, 50), 0, 360);
	graphBackBuffer->DrawArc(pen, Rect(75, 80, 100, 100), 0, 360);
	graphBackBuffer->DrawArc(pen, Rect(150, 50, 50, 50), 0, 360);
	graphBackBuffer->DrawArc(pen, Rect(110, 135, 30, 15), 0, 360);
	graphBackBuffer->DrawArc(pen, Rect(100, 130, 50, 35), 200, 140);
	graphBackBuffer->DrawArc(pen, Rect(105, 100, 15, 35), 105, 320); 
	graphBackBuffer->DrawArc(pen, Rect(130, 100, 15, 35), 115, 320);
	
}

void Test_DrawRect(Graphics* graphBackBuffer,void * pParam)
{
	
	Pen *pen = *(Pen **)pParam;
	graphBackBuffer->DrawRectangle(pen, Rect(160, 100, 50, 50));
}

void Test_DrawCurve(Graphics* graphBackBuffer, void * pParam)
{
	Pen *pen, *pen2;
	Brush *brush;

	pen = *(Pen **)pParam;
	pen2 = *(Pen **)((BYTE *)pParam + 4);
	brush = *(Brush **)((BYTE *)pParam + 8);

	//곡선 그리기
	Point points[] = { Point(50,50),Point(80,90),Point(120,90),Point(150,50) };

	for (int i = 0; i < 4; i++) {
		graphBackBuffer->TranslateTransform(-4, -4);
		graphBackBuffer->FillRectangle(brush, Rect(points[i], Size(8, 8)));
		graphBackBuffer->ResetTransform();
	}

	graphBackBuffer->DrawCurve(pen, points, 4);

	graphBackBuffer->DrawBezier(pen2, points[0], points[1], points[2], points[3]);
	
}

void GDIPLUS_Loop(MSG &msg)
{
	//----------------------------------------------------------------------
	//gdi plus 초기화 코드 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//-----------------------------------------------------------------------

	{
		bool quit = false;
		//gdiplus 가 셧다운 되기전에 객체들이 삭제되어야 하므로 일부러 지역변수선언을 한단계 내려서 사용했다.
		Gdiplus::Rect rectScreen(0, 0, 320, 240);
		Bitmap bmpMem(rectScreen.Width, rectScreen.Height);
		Graphics* graphBackBuffer = Graphics::FromImage(&bmpMem);

		Pen penRed(Color(255, 0, 0));
		Pen penYellow(Color(255, 255, 0));
		Pen penWhite(Color(255, 255, 255));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		Gdiplus::SolidBrush brushWhite(Color(255, 255, 255));
		Gdiplus::SolidBrush brushGreen(Color(0, 255, 0));
		FontFamily  fontFamily(L"굴림");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		static LONG prev_tick;
		static SYSTEMTIME time;

		void(*Test_DrawFp)(Graphics* graphBackBuffer,void *);
		void *pThisParam;
		Test_DrawFp = NULL;
		pThisParam = NULL;

		void * pTemp;
		BYTE bufTest_DrawPath_Parm[256];
		pTemp = bufTest_DrawPath_Parm;
		{
			//DWORD nTemp = (DWORD)&penRed;
			//memcpy(pTemp, &penRed, 4);
			*(int *)pTemp = (DWORD)&penRed;
		}
		BYTE bufTest_DrawRect_Parm[256];
		//pTemp = bufTest_DrawRect_Parm;
		{
			DWORD nTemp = (DWORD)&penWhite;
			memcpy(pTemp, &nTemp, 4);
		}
		BYTE bufTest_DrawCurve_Parm[256];
		pTemp = bufTest_DrawCurve_Parm;
		DWORD nTemp = (DWORD)&penYellow;
		{
			*(DWORD *)pTemp = (DWORD)&penRed;
			*(DWORD *)((BYTE *)pTemp + 4) = (DWORD)&penWhite;
			*(DWORD *)((BYTE *)pTemp + 8) = (DWORD)&brushGreen;
			/*DWORD nTemp = (DWORD)&penYellow;
			memcpy(pTemp, &penYellow, 4);
			nTemp = (DWORD)&penWhite;
			memcpy((BYTE*)pTemp + 4, &penRed, 4);
			nTemp = (DWORD)&brushGreen;
			memcpy((BYTE*)pTemp + 8, &brushGreen, 4);*/
		}
		while (!quit) {

			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					quit = true;
				else if (msg.message == WM_COMMAND) {
					switch (msg.wParam)
					{
					case IDM_START:
						StartGDILoop();
						break;
					case IDM_TEST_PATH:
						pThisParam = bufTest_DrawPath_Parm;
						Test_DrawFp = Test_DrawPath;
						break;
					case IDM_TEST_RECT:
						pThisParam = bufTest_DrawRect_Parm;
						Test_DrawFp = Test_DrawRect;
						break;
					case IDM_TEST_NONE:
						Test_DrawFp = NULL;
						break;
					case IDM_TEST_CURVE:
						pThisParam = bufTest_DrawCurve_Parm;
						Test_DrawFp = Test_DrawCurve;
						break;
					default:
						break;
					}
				}
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				switch (g_dwGdiLoopFsm)
				{
				case 0:
					break;
				case 10:
				{
					GetSystemTime(&time);
					LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
					float fDelta = (time_ms - prev_tick) / 1000.f;
					prev_tick = time_ms;

		

					//랜더링 
					HDC hdc = GetDC(msg.hwnd);
					{
						Graphics graphics(hdc);
						graphBackBuffer->FillRectangle(&brushBlack, rectScreen);
						if (Test_DrawFp != NULL) {
							Test_DrawFp(graphBackBuffer ,pThisParam);
						}
						
						graphics.DrawImage(&bmpMem, rectScreen);
					}
					ReleaseDC(msg.hwnd, hdc);
				}
				break;
				default:
					break;
				}


			}
		}
	}

	//--------------------------------------
	//gdi plus 종료코드 
	GdiplusShutdown(gdiplusToken);
	//--------------------------------------


}