#pragma once
#include "bullet.h"

void OnCreate(HWND hWNd);
void OnRender(double fDelta, Graphics* grp_);
void OnLoop(double fDelta);
void OnDestroy();
int Count(Bullet** bullets, int size);
int CreateBullet();
int CreateBullet2();
extern int CreateExplosion(irr::core::vector2df pos);