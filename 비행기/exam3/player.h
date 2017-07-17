#pragma once
#include "bullet.h"

struct Player {
	irr::core::vector2df pos;
	Image* img;
	int score = 0;
	int life = 8;
	double speed = 3;
	double slowFactor = .4;
	double time;
	double shootInterval = 0.1;
	bool destroy = false;
	int FSM;

	void OnApply(double fDelta);
	void OnRender(Graphics* grp_);
	void Setup(irr::core::vector2df& startPos, Image* img);
	void OnDamage(Bullet& bullet);
	void Move(double fDelta);
	int Shoot(double fDelta);
};

