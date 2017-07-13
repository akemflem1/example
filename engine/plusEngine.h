#pragma once

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace plusEngine {
	extern void startUpGdiPlus();
	extern void CloseGdiPlus();
	extern void printf(Graphics *grp, int x, int y, TCHAR *fmt, ...);
}