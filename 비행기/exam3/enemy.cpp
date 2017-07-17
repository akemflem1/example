#include "stdafx.h"
extern Rect rectScreen;

void Enemy::OnApply(double fDelta) {
	Move(fDelta);
}

void Enemy::OnRender(Graphics* grp_) {
	Graphics& grp = *grp_;
	int w = img->GetWidth();
	int h = img->GetHeight();
	grp.DrawImage(img, Rect(pos.X - w / 2, pos.Y - h / 2, w, h));
}

void Enemy::Setup(irr::core::vector2df& startPos, Image* img) {
	pos.set(startPos.X, startPos.Y);
	this->img = img;
}

void Enemy::OnDamage(Bullet& bullet) {
	hp -= bullet.power;
	if (hp <= 0) {
		OnDestroy();
	}
}

void Enemy::Move(double fDelta) {

}

void Enemy::OnDestroy() {
	FSM = 20;
	destroy = true;
}