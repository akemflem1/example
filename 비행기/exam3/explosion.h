#pragma once

struct Explosion {
	irr::core::vector2df pos;
	double time = 0;
	int FSM = 0;
	Image* img;
	bool destroy = false;
	double limit_time;
	double alpha = 1;

	void OnApply(double fDelta);
	void OnRender(Graphics* grp_);
	void Setup(irr::core::vector2df& pos, double time, Image* img);
	void OnDestroy();
};