#pragma once

struct GameObject
{
	// 0 �غ�, 10 �߻�, 20 ����
	int m_nFSM;
	irr::core::vector2df m_position;
	irr::f64 m_fRotation;
	irr::f64 m_fSpeed;
	irr::f64 m_fFuel;
	
	Image *m_pImg;
};

extern void GameObject_Draw(GameObject *pThis, Graphics &grp);
extern void GameObject_Apply(GameObject *pThis, irr::f64 fDelta);