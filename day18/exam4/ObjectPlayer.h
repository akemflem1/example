#pragma once

struct S_ObjctPlayer
{
	irr::core::vector2df m_vPosition;
	Image *m_pImg;
		 
};

extern void S_ObjctPlayer_OnApply(S_ObjctPlayer *pThis, double fDelta);
extern void S_ObjctPlayer_OnRender(S_ObjctPlayer *pThis, Graphics *pGrp);
extern void S_ObjctPlayer_Setup(S_ObjctPlayer *pThis, irr::core::vector2df &startPos, Image *pImg);