#include "stdafx.h"

void ObjectEffectBulletDie_OnApply(S_ObjectEffectBulletDie *pThis, double fDelta)
{
	

	switch (pThis->m_nFSM)
	{
	case 0:
		pThis->m_nFSM = 10;
		break;
	case 10:
		pThis->m_fLifeTime += fDelta;
		if (pThis->m_fLifeTime > 3.0) {
			pThis->m_nFSM = 999;
		}
		break;
	default:
		break;
	}

}

void ObjectEffectBulletDie_OnRender(S_ObjectEffectBulletDie *pThis, Graphics *pGrp)
{
	Pen pen(Color(255, 0, 0));
	Matrix tempMat;
	pGrp->GetTransform(&tempMat);
	pGrp->TranslateTransform(pThis->m_vPosition.X, pThis->m_vPosition.Y);
	pGrp->ScaleTransform(pThis->m_fLifeTime , pThis->m_fLifeTime);
	pGrp->DrawEllipse(&pen, -4, -4, 8, 8);
	pGrp->SetTransform(&tempMat);
}

void ObjectEffectBulletDie_Setup(S_ObjectEffectBulletDie *pThis, irr::core::vector2df vPos)
{
	pThis->m_vPosition = vPos;
	pThis->m_fLifeTime = 0;
	pThis->m_nFSM = 0;
}