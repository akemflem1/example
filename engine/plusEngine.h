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
}
