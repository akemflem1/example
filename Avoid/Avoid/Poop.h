#pragma once

struct poop
{
	irr::core::vector2df position;
	irr::core::vector2df m_vDirection;
	irr::f64 m_fVelocity;
	irr::f64 m_fSize;
	int m_nFSM;
	Image *img;
	double m_fLifeTime;
};

extern void poop_OnApply(poop *pThis, double fDelta);
extern void poop_OnRender(poop *pThis, Graphics *pGrp);
extern void poop_Setup(poop *pThis, irr::core::vector2df &vStartPos, irr::core::vector2df &vTargetPos, irr::f64 fVolumeSize, irr::f64 fVelocity);