#pragma once

struct Bullet {
	void* mother; // NULL:enemy, &player:player
	irr::core::vector2df pos;
	irr::core::vector2df speed;
	double angle;
	Image* img;
	double r;
	int FSM;
	irr::core::vector2df* tracking;
	bool rotatable = false;
	bool destroy = false;
	double power = 1;

	void OnApply(double fDelta);
	void OnRender(Graphics* grp_);
	void Setup(void* mother, irr::core::vector2df& startPos, irr::core::vector2df& speed, bool rotatable, irr::core::vector2df* tracking, Image* img);
	void OnDestroy();
};