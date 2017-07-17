#include "stdafx.h"

void poop_OnApply(poop *pThis, double fDelta)
{
	pThis->m_fLifeTime += fDelta;

	switch (pThis->m_nFSM)
	{
	case 0:
		pThis->m_nFSM = 10;
		break;
	case 10:
	{
		pThis->position += pThis->m_vDirection * pThis->m_fVelocity * fDelta;

		irr::f64 fDist = (pThis->position - body.m_vPosition).getLength();
		//총알 + 비행기 크기
		if (fDist < (pThis->m_fSize + 12)) {
			pThis->m_nFSM = 999;
			//AddEffectBulletDie(pThis->m_vPosition);
		}
		//라이프타임 검사
		if (pThis->m_fLifeTime > 10) {
			pThis->m_nFSM = 999;
		}
	}
	break;
	default:
		break;
	}
}

void poop_OnRender(poop *pThis, Graphics *pGrp)
{
	pGrp->DrawImage(pThis->img, RectF(pThis->position.X - 17 / 2, pThis->position.Y - 17 / 2, 17, 17));
}

void poop_Setup(poop *pThis, irr::core::vector2df &vStartPos, irr::core::vector2df &vTargetPos, irr::f64 fVolumeSize, irr::f64 fVelocity, Image *pImg)
{
	pThis->m_fSize = fVolumeSize;
	pThis->m_fVelocity = fVelocity;
	pThis->m_nFSM = 0;
	pThis->position = vStartPos;
	pThis->m_vDirection = vTargetPos - vStartPos;
	pThis->m_vDirection.normalize();
	pThis->m_fLifeTime = 0;
	pThis->img = pImg;
}