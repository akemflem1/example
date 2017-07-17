#include "stdafx.h"
#include "bullet.h"
extern Rect rectScreen;
extern Bullet* bullets[];
extern Enemy* enemys[];
extern Player player;

void Bullet::OnApply(double fDelta) {
	switch (FSM) {
	case 0:
		FSM = 10;
		break;
	case 10:
	{
		if (tracking) {
			irr::core::vector2df dir = *tracking - pos;
			dir.normalize();
			double p = 0.008;
			speed += dir * p;
			if (speed.getLength() > 2.0) {
				speed.normalize();
				speed *= 2.0;
			}
		}

		pos += speed;
		if (rotatable)
			angle = atan2f(speed.Y, speed.X) / PI * 180 + 90;

		// Collision detection
		if (mother != &player) {
			double d = pos.getDistanceFrom(player.pos);
			if (d < hypot(img->GetWidth(), img->GetHeight()) * .5) {
				CreateExplosion(pos);
				player.OnDamage(*this);
				OnDestroy();
				return;
			}
		}
		else {
			for (int i = 0; i < MAX_ENEMY; i++) {
				if (!enemys[i])
					continue;
				double d = pos.getDistanceFrom(enemys[i]->pos);
				if (d < hypot(img->GetWidth(), img->GetHeight()) * 0 + hypot(enemys[i]->img->GetWidth(), enemys[i]->img->GetHeight()) * .4) {
					CreateExplosion(pos);
					enemys[i]->OnDamage(*this);
					OnDestroy();
					return;
				}
			}
		}

		// Delete when out of screen
		if (pos.X < -30 || pos.X > rectScreen.Width - 1 + 30 || pos.Y < 0 - 30 || pos.Y > rectScreen.Height - 1 + 30) {
			FSM = 20;
			break;
		}
	}
		break;
	case 20:
		OnDestroy();
		break;
	}
}

void Bullet::OnRender(Graphics* grp_) {
	Graphics& grp = *grp_;
	int w = img->GetWidth();
	int h = img->GetHeight();
	Matrix orgTrans;
	grp.GetTransform(&orgTrans);

	grp.TranslateTransform(pos.X, pos.Y);
    grp.RotateTransform(angle);
	grp.DrawImage(img, Rect(- w / 2,- h / 2, w, h));

	grp.SetTransform(&orgTrans);
}

void Bullet::Setup(void* mother, irr::core::vector2df& startPos, irr::core::vector2df& speed, bool rotatable, irr::core::vector2df* tracking, Image* img) {
	this->mother = mother;
	pos.set(startPos.X, startPos.Y);
	this->speed = speed;
	this->img = img;
	this->rotatable = rotatable;
	this->tracking = tracking;
	FSM = 0;
}

void Bullet::OnDestroy() {
	FSM = 20;
	destroy = true;
}