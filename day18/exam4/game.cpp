#include "stdafx.h"

HWND g_hWnd;

#define MAX_BULLET_LIST 16
#define MAX_EFFECT_BULLETDIE_LIST 16

BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer;
//S_ObjectBullet g_TestBullet;
S_ObjectBullet *g_Bullet_List[MAX_BULLET_LIST];
S_ObjectEffectBulletDie *g_BulletDie_List[MAX_EFFECT_BULLETDIE_LIST];

Image *g_pImgSpaceShip;
Image *g_pImgPoop;

irr::f64 g_fAcctick = 0;
// -1: 생성실패
int AddBullet()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i + 1;
		}
	}
	return -1;
}

int AddBullet2()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

int AddBullet3()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

int AddBullet4()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

int AddBullet5()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

int AddBullet6()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 320 - 160, -200), g_objPlayer.m_vPosition, 8, rand() % 100 + 70);
			g_Bullet_List[i] = ptr;
			return i;
		}
	}
	return -1;
}


int AddEffectBulletDie(irr::core::vector2df pos)
{
	int i;
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		if (g_Bullet_List[i] == NULL) {
			S_ObjectEffectBulletDie *ptr = (S_ObjectEffectBulletDie *)malloc(sizeof(S_ObjectEffectBulletDie));
			ObjectEffectBulletDie_Setup(ptr, pos);
			g_BulletDie_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

void ClearDeadBulletObj()
{
	//시체처리
	int i;
	for (i = 0; i <MAX_BULLET_LIST; i++) {

		if (g_Bullet_List[i] != NULL && g_Bullet_List[i]->m_nFSM == 999) {
			free(g_Bullet_List[i]);
			g_Bullet_List[i] = NULL;
		}
	}
}


void ClearDeadEffecBulletDieObj()
{
	int i;
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

		if (g_BulletDie_List[i] != NULL && g_BulletDie_List[i]->m_nFSM == 999) {
			free(g_BulletDie_List[i]);
			g_BulletDie_List[i] = NULL;
		}
	}
}

void OnLoop(double fDelta)
{	
	if (fDelta < 0 || fDelta>1) {
		fDelta = 0;
	}
	//시체처리
	ClearDeadBulletObj();
	ClearDeadEffecBulletDieObj();
	//총알발사
	g_fAcctick += fDelta;
	if (g_fAcctick > 3.0) {
		g_fAcctick = 0.0;
		AddBullet();
		AddBullet2();
		AddBullet3();
		AddBullet4();
		AddBullet5();
		AddBullet6();
	}
	//플레이어 처리
	S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);
	//ObjectBullet_OnApply(&g_TestBullet, fDelta);
	//총알처리
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		S_ObjectBullet *ptr = g_Bullet_List[i];
		if (ptr != NULL) {
			ObjectBullet_OnApply(ptr, fDelta);
		}
	}
	//파괴효과
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		S_ObjectEffectBulletDie *ptr = g_BulletDie_List[i];
		if (ptr != NULL) {
			ObjectEffectBulletDie_OnApply(ptr, fDelta);
		}
	}
}

void OnRender(double fDelta,Graphics *pGrp)
{
	pGrp->Clear(Color(200,191,231));
	if (fDelta > 0) {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1.0 / fDelta);
	}
	else {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1000.f);
	}
	Pen pen(Color(0, 0, 0));
	//Pen pen2(Color(255, 0, 0));
	pGrp->DrawRectangle(&pen, 0, 0, 320, 400);
	pGrp->DrawLine(&pen, 0, 200, 320, 200);
	pGrp->DrawLine(&pen, 160, 0, 160, 400);

	Matrix originMat(1, 0, 0, 1, 160, 200);
	pGrp->SetTransform(&originMat);


	S_ObjectPlayer_OnRender(&g_objPlayer, pGrp);
	//ObjectBullet_OnRender(&g_TestBullet, pGrp);
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		S_ObjectBullet *ptr = g_Bullet_List[i];
		if (ptr != NULL) {
			ObjectBullet_OnRender(ptr, pGrp);
		}
	}

	//파괴효과
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		S_ObjectEffectBulletDie *ptr = g_BulletDie_List[i];
		if (ptr != NULL) {
			ObjectEffectBulletDie_OnRender(ptr, pGrp);
		}
	}

	pGrp->ResetTransform();
}

void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	//키상태 초기화
	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		g_Bullet_List[i] = NULL;
	}

	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		g_BulletDie_List[i] = NULL;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");
	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(0, 0), g_pImgSpaceShip);
	g_pImgPoop = new Image(L"../../res/poop_small.png");
	//ObjectBullet_Setup(&g_TestBullet, irr::core::vector2df(0, 100), g_objPlayer.m_vPosition, 8,30, g_pImgPoop);
}

void OnDestroy(HWND hWnd)
{
	delete g_pImgSpaceShip;

	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_Bullet_List[i] != NULL) {
			free(g_Bullet_List[i]);
		}
	}
}