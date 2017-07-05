#include "stdafx.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")


int g_MapRoom1[] = {
	3, 0, 0, 0, 0, 0, 0, 3,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	2, 2, 48, 2, 2, 2, 2, 2
};

int g_MapAttrBlock[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int g_nPlayerXpos = 3;
int g_nPlayerYpos = 3;

//문열림 스위치 오브젝트
int g_nItemSwitchXpos = 5;
int g_nItemSwitchYpos = 3;
int g_nItemSwitchSprIndex = 47;
int g_nItemSwitchStatus = 0; // 0: 스위치 미작동 1: 스위치 작동

const int g_nTileSize = 16;
const int g_nTileXCount = 8;

int getMapBlockAttr(int mx, int my)
{
	return g_MapAttrBlock[my * 8 + mx];
}

void eventKeyDown(WPARAM wParam)
{
	int savePosx = g_nPlayerXpos;
	int savePosy = g_nPlayerYpos;

	switch(wParam)
	{
	case VK_UP:
		g_nPlayerYpos--;
		break;
	case VK_DOWN:
		g_nPlayerYpos++;
		break;
	case VK_LEFT:
		g_nPlayerXpos--;
		break;
	case VK_RIGHT:
		g_nPlayerXpos++;
		break;
	default:
		break;
	}
	if (getMapBlockAttr(g_nPlayerXpos, g_nPlayerYpos) == 1) {
		g_nPlayerXpos = savePosx;
		g_nPlayerYpos = savePosy;
	}
}

void drawTileIndex(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int nTileIndex)
{
	//int nTileIndex = pMap[nPosX + nPosY*g_nTileXCount];

	pGrp->DrawImage(pImgBasicTile, Rect(nPosX * 16, nPosY * 16, g_nTileSize, g_nTileSize), 
		g_nTileSize * (nTileIndex % g_nTileXCount), g_nTileSize * (nTileIndex / g_nTileXCount), 
		g_nTileSize, g_nTileSize, UnitPixel);
}

void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int *pMap)
{
	int nTileIndex = pMap[nPosX + nPosY*g_nTileXCount];
	drawTileIndex(pGrp, pImgBasicTile, nPosX, nPosY, nTileIndex);
}

DWORD g_dwGdiLoopFsm = 0; //루프상태제어
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
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		Gdiplus::SolidBrush brushWhite(Color(255, 255, 255));
		FontFamily  fontFamily(L"굴림");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		static LONG prev_tick;
		static SYSTEMTIME time;

		Image imgBasicTile(L"../../res/basic_tile/basictiles.png"); // 16x16
																	//Image imgPlayer(L"../../res/potrait/Pepper publish.png");// 24 x 32
		Image imgPlayer(L"../../res/charater.png");// 64 x 64

												   //Image imgitem(L"../../res/Items.png");

		while (!quit) {

			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					quit = true;
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
					
					//게임 로직
					{
						if (g_nItemSwitchStatus == 0) {
							if (g_nItemSwitchXpos == g_nPlayerXpos && g_nItemSwitchYpos == g_nPlayerYpos) {
								g_nItemSwitchStatus = 1;
								g_MapAttrBlock[8 * 7 + 2] = 0; // (7,2) 위치 막힘제거
							}
						}

					}
					//랜더링
					HDC hdc = GetDC(msg.hwnd);
					{
						Graphics graphics(hdc);
						graphBackBuffer->FillRectangle(&brushBlack, rectScreen);

						//지도 그리기 
						for (int ix = 0; ix < 8; ix++) {
							for (int iy = 0; iy < 8; iy++) {
								drawTile(graphBackBuffer, &imgBasicTile,
									ix, iy, g_MapRoom1);
							}
						}

						graphBackBuffer->DrawImage(&imgPlayer,
							Rect((g_nPlayerXpos * 16) - 8, (g_nPlayerYpos * 16) - 16, 32, 32), //대상위치 
							0, 64 * 2, 64, 64, //원본위치 
							UnitPixel
						);

						//각종 아이텝, 트리거, 기구물 그리기
						if (g_nItemSwitchStatus == 0) {
							drawTileIndex(graphBackBuffer, &imgBasicTile, g_nItemSwitchXpos, g_nItemSwitchYpos, 47);
						}
						else {

						}
						graphics.ScaleTransform(2.0, 2.0);
						graphics.DrawImage(&bmpMem, rectScreen);
						graphics.ResetTransform();
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