#include "stdafx.h"

void GameObject_Apply(GameObject *pThis, irr::f64 fDelta)
{
	irr::core::vector2df vDir(1,0);
	vDir.rotateBy(pThis->m_fRotation);
	pThis->m_position += (vDir * pThis->m_fSpeed * fDelta);
}

void GameObject_Draw(GameObject *pThis, Graphics &grp)
{
	grp.DrawImage(pThis->m_pImg, pThis->m_position.X-32, pThis->m_position.Y-16,pThis->m_pImg->GetWidth(), pThis->m_pImg->GetHeight());
}