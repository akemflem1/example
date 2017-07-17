#include "stdafx.h"

#define MAX_POOP 16

BYTE keyStatus[256];
poop *poops[MAX_POOP] = {};

Image *g_pImgSpaceShip;
Image *g_pImgPoop;



int CreatePoop(void* mother) {
	for (int i = 0; i < MAX_POOP; i++) {
		if (!poops[i]) {
			poop *poop = new poop;
			irr::core::vector2df startPos(rand() % 320 - 160);
			double s = 1.0;
			irr::core::vector2df speed;
			speed = body.pos - startPos;
			speed.normalize();
			speed.rotateBy(rand() % 60 - 60 / 2.);
			speed *= s;
			poop_Setup(pThis->, startPos, speed, true, NULL, imgBullet);
			
			bullets[i] = bullet;
			return 1;
		}
	}
	return 0;
}

void OnLoop(double fDelta)
{
	
}

void OnRender(double fDelta, Graphics *pGrp)
{
	Pen pen(Color(0, 0, 0));
	pGrp->DrawRectangle(&pen, 0, 0, 320, 400);
	Matrix baseMat(1, 0, 0, 1, 160, 200);
	pGrp->SetTransform(&baseMat);

	pGrp->ResetTransform();
}

void OnCreate(HWND hWnd)
{
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;

	for (int i = 0; i < 256; i++) {
		keyStatus[i] = 0;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");
	g_pImgPoop = new Image(L"../../res/poop_small.png");
	player_Setup(&body, irr::core::vector2df(0, 0), g_pImgSpaceShip);
}

void OnDestroy(HWND hWnd)
{
	
}