#include "stdafx.h"

void player_OnApply(player *pThis, double fDelta)
{
	if (keyStatus[VK_LEFT]) {
		pThis->position += fDelta * 50 * irr::core::vector2df(-1, 0);
	}
	if (keyStatus[VK_RIGHT]) {
		pThis->position += fDelta * 50 * irr::core::vector2df(1, 0);
	}
	if (keyStatus[VK_UP]) {
		pThis->position += fDelta * 50 * irr::core::vector2df(0, -1);
	}
	if (keyStatus[VK_DOWN]) {
		pThis->position += fDelta * 50 * irr::core::vector2df(0, 1);
	}
	if (pThis->position.X > 160 - 43 / 2)
	{
		pThis->position.X -= 1;
	}
	if (pThis->position.X < -160 + 43 / 2)
	{
		pThis->position.X += 1;
	}
	if (pThis->position.Y > 200 - 35 / 2)
	{
		pThis->position.Y -= 1;
	}
	if (pThis->position.Y < -200 + 35 / 2)
	{
		pThis->position.Y += 1;
	}
}

void player_OnRender(player *pThis, Graphics *pGrp)
{
	pGrp->DrawImage(pThis->img, RectF(pThis->position.X - 43 / 2, pThis->position.Y - 35 / 2, 43, 35));
}

void player_Setup(player *pThis, irr::core::vector2df &startPos, Image *pImg)
{
	pThis->img = pImg;
	pThis->position = startPos;
}