#include "stdafx.h"

void S_ObjctPlayer_OnApply(S_ObjctPlayer *pThis, double fDelta)
{
	if (g_KeyStatus[VK_LEFT]) {
		pThis->m_vPosition += fDelta * 10 * irr::core::vector2df(-1, 0);
	}
	if (g_KeyStatus[VK_RIGHT]) {
		pThis->m_vPosition += fDelta * 10 * irr::core::vector2df(1, 0);
	}
	if (g_KeyStatus[VK_UP]) {
		pThis->m_vPosition += fDelta * 10 * irr::core::vector2df(0, -1);
	}
	if (g_KeyStatus[VK_DOWN]) {
		pThis->m_vPosition += fDelta * 10 * irr::core::vector2df(0, 1);
	}

}

void S_ObjctPlayer_OnRender(S_ObjctPlayer *pThis, Graphics *pGrp)
{
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 43 / 2, pThis->m_vPosition.Y - 35 / 2, 43, 35));
}

void S_ObjctPlayer_Setup(S_ObjctPlayer *pThis, irr::core::vector2df &startPos, Image *pImg)
{
	pThis->m_pImg = pImg;
	pThis->m_vPosition = startPos;
}