#pragma once

struct player
{
	irr::core::vector2df position;
	Image *img;
};

void player_OnApply(player *pThis, double fDelta);
void player_OnRender(player *pThis, Graphics *pGrp);
void player_Setup(player *pThis, irr::core::vector2df &startPos, Image *pImg);