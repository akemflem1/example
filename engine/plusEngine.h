#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace plusEngine {
	extern void startUpGdiPlus();
	extern void CloseGdiPlus();
	extern void printf(Graphics *grp, int x, int y, TCHAR *fmt, ...);

	extern void(*fpOnLoop)(double);
	extern void(*fpOnRender)(double, Graphics*);
	extern void GDIPLUS_Loop(MSG &msg, Gdiplus::Rect rectScreen);
	
	namespace util {

		inline PointF irr2Point(irr::core::vector2df &a)
		{
			PointF b;
			b.X = a.X;
			b.Y = a.Y;

			return b;
		}
		inline PointF irr2Point(irr::core::vector3df &a)
		{
			return irr2Point(irr::core::vector2df(a.X, a.Y));
		}

		inline RectF irr2Rect(irr::core::vector2df &pos, irr::core::vector2df &size)
		{
			RectF c;
			c.X = pos.X;
			c.Y = pos.Y;
			c.Width = size.X;
			c.Height = size.Y;

			return c;
		}
		inline RectF irr2Rect(irr::core::vector3df &pos, irr::core::vector3df &size)
		{
			return irr2Rect(irr::core::vector2df(pos.X, pos.Y), irr::core::vector2df(size.X, size.Y));
		}

	}
}

