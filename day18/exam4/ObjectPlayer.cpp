#include "stdafx.h"

void S_ObjectPlayer_OnApply(S_ObjectPlayer *pThis, double fDelta)
{
	if (g_KeyStatus[VK_LEFT]) {
		pThis->m_vPosition += fDelta * 50 * irr::core::vector2df(-1, 0);
	}
	if (g_KeyStatus[VK_RIGHT]) {
		pThis->m_vPosition += fDelta * 50 * irr::core::vector2df(1, 0);
	}
	if (g_KeyStatus[VK_UP]) {
		pThis->m_vPosition += fDelta * 50 * irr::core::vector2df(0, -1);
	}
	if (g_KeyStatus[VK_DOWN]) {
		pThis->m_vPosition += fDelta * 50 * irr::core::vector2df(0, 1);
	}
	if (pThis->m_vPosition.X > 160 - 43 / 2)
	{
	pThis->m_vPosition.X -= 1;
	}
	if (pThis->m_vPosition.X < -160 + 43 / 2)
	{
		pThis->m_vPosition.X += 1;
	}
	if (pThis->m_vPosition.Y > 200 - 35 / 2)
	{
		pThis->m_vPosition.Y -= 1;
	}
	if (pThis->m_vPosition.Y < -200 + 35 / 2)
	{
		pThis->m_vPosition.Y += 1;
	}
}

void S_ObjectPlayer_OnRender(S_ObjectPlayer *pThis, Graphics *pGrp)
{
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 43 / 2, pThis->m_vPosition.Y - 35 / 2, 43, 35));
}

void S_ObjectPlayer_Setup(S_ObjectPlayer *pThis, irr::core::vector2df &startPos, Image *pImg)
{
	pThis->m_pImg = pImg;
	pThis->m_vPosition = startPos;
}