#pragma once

struct S_ObjectEffectBulletDie
{
	irr::core::vector2df m_vPosition;
	irr::f32 m_fLifeTime;
	int m_nFSM;

};


extern void ObjectEffectBulletDie_OnApply(S_ObjectEffectBulletDie *pThis, double fDelta);
extern void ObjectEffectBulletDie_OnRender(S_ObjectEffectBulletDie *pThis, Graphics *pGrp);
extern void ObjectEffectBulletDie_Setup(S_ObjectEffectBulletDie *pThis, irr::core::vector2df vPos);