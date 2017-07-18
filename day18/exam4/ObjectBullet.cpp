#include "stdafx.h"

void ObjectBullet_OnApply(S_ObjectBullet *pThis, double fDelta)
{
	pThis->m_fLifeTime += fDelta;
	
	switch (pThis->m_nFSM)
	{
	case 0:
		pThis->m_nFSM = 10;
		break;
	case 10:
	{
		pThis->m_vPosition += pThis->m_vDirection * pThis->m_fVelocity * fDelta;

		irr::f64 fDist = (pThis->m_vPosition - g_objPlayer.m_vPosition).getLength();
		//총알 + 비행기 크기
		if (fDist < (pThis->m_fSize + 15)) {
			pThis->m_nFSM = 999;
			AddEffectBulletDie(pThis->m_vPosition);
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

void ObjectBullet_OnRender(S_ObjectBullet *pThis, Graphics *pGrp)
{
	//Pen pen(Color(0, 0, 0));
	//pGrp->DrawEllipse(&pen, pThis->m_vPosition.X - pThis->m_fSize/2, pThis->m_vPosition.Y-pThis->m_fSize/2, (int)pThis->m_fSize, (int)pThis->m_fSize);
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 17 / 2, pThis->m_vPosition.Y - 17 / 2, 17, 17));
}

void ObjectBullet_Setup(S_ObjectBullet *pThis, irr::core::vector2df &vStartPos, irr::core::vector2df &vTargetPos,irr::f64 fVelocity, Image* img)
{
	pThis->m_fVelocity = fVelocity;
	pThis->m_nFSM = 0;
	pThis->m_vPosition = vStartPos;
	pThis->m_vDirection = vTargetPos - vStartPos;
	pThis->m_vDirection.normalize();
	pThis->m_fLifeTime = 0;
	pThis->m_pImg = img;
}
