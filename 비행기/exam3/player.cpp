#include "stdafx.h"
extern Rect rectScreen;
extern Image* imgBullet;
extern Bullet* bullets[];
extern HWND mainWindow;

void Player::OnApply(double fDelta) {
	Move(fDelta);

	if (GetAsyncKeyState('Z'))
		Shoot(fDelta);
}

void Player::OnRender(Graphics* grp_) {
	Graphics& grp = *grp_;
	int w = img->GetWidth();
	int h = img->GetHeight();
	grp.DrawImage(img, Rect(pos.X-w/2, pos.Y-h/2, w, h));
}

void Player::Setup(irr::core::vector2df& startPos, Image* img) {
	pos.set(startPos.X, startPos.Y);
	this->img = img;
	time = clock();
	FSM = 0;
}

void Player::OnDamage(Bullet& bullet) {
	life--;
	FSM = 20;
}

void Player::Move(double fDelta) {
	int countKey = !!GetAsyncKeyState(VK_UP) + !!GetAsyncKeyState(VK_DOWN) + !!GetAsyncKeyState(VK_LEFT) + !!GetAsyncKeyState(VK_RIGHT);

	double gamma = 0;
	gamma = 1 / pow(countKey, 0.5);
	if (GetAsyncKeyState(VK_LSHIFT))
		gamma *= slowFactor;
	if (GetAsyncKeyState(VK_UP))
		pos += irr::core::vector2df(0, -speed) * gamma;
	if (GetAsyncKeyState(VK_DOWN))
		pos += irr::core::vector2df(0, +speed) * gamma;
	if (GetAsyncKeyState(VK_LEFT))
		pos += irr::core::vector2df(-speed, 0) * gamma;
	if (GetAsyncKeyState(VK_RIGHT))
		pos += irr::core::vector2df(+speed, 0) * gamma;
	if (pos.X < 0)
		pos.set(0, pos.Y);
	if (pos.X > rectScreen.Width - 1)
		pos.set(rectScreen.Width - 1, pos.Y);
	if (pos.Y < 0)
		pos.set(pos.X, 0);
	if (pos.Y > rectScreen.Height - 1)
		pos.set(pos.X, rectScreen.Height - 1);
}

int Player::Shoot(double fDelta) {
	int t = clock();
	if (t - time < shootInterval * 1000)
		return -1;
	time = t;

	for (int i = 0; i < MAX_BULLET; i++) {
		if (!bullets[i]) {
			Bullet* bullet = new Bullet;
			int h = imgBullet->GetHeight();
			irr::core::vector2df startPos(pos.X, pos.Y - 10);
			irr::core::vector2df speed(0, -4);
			bullet->Setup(this, startPos, speed, true, NULL, imgBullet);
			bullets[i] = bullet;
			return 1;
		}
	}
	return 0;
}