#pragma once
#include "bullet.h"

struct Enemy {
	irr::core::vector2df pos;
	Image* img;
	int score = 0;
	double hp = 1;
	double speed = 3;
	bool destroy = false;
	int FSM;

	void OnApply(double fDelta);
	void OnRender(Graphics* grp_);
	void Setup(irr::core::vector2df& startPos, Image* img);
	void OnDamage(Bullet& bullet);
	void Move(double fDelta);
	void OnDestroy();
};

