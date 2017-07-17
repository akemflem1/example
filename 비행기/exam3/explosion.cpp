#include "stdafx.h"

void Explosion::OnApply(double fDelta) {
	switch (FSM) {
	case 0:
		time += fDelta;
		alpha = 1 - time / limit_time;
		if (time > limit_time) {
			FSM = 20;
			break;
		}
		break;
	case 20:
		OnDestroy();
		break;
	}
}

void Explosion::OnRender(Graphics* grp_) {
	Graphics& grp = *grp_;
	int w = img->GetWidth();
	int h = img->GetHeight();
	Matrix orgTrans;
	grp.GetTransform(&orgTrans);

	grp.TranslateTransform(pos.X, pos.Y);

	ColorMatrix ClrMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, alpha, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	ImageAttributes imgAttr;
	imgAttr.SetColorMatrix(&ClrMatrix, ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);

	grp.DrawImage(img, Rect(-w / 2, -h / 2, w, h), 0, 0, img->GetWidth(), img->GetHeight(), UnitPixel, &imgAttr);

	grp.SetTransform(&orgTrans);
}

void Explosion::Setup(irr::core::vector2df& pos, double time, Image* img) {
	this->pos.set(pos.X, pos.Y);
	this->img = img;
	FSM = 0;
	limit_time = time;
}

void Explosion::OnDestroy() {
	destroy = true;
}
