#include "stdafx.h"
#include "plusEngine.h"

namespace plusEngine {
	//gdi plus 초기화 코드 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	
	void startUpGdiPlus()
	{
		//----------------------------------------------------------------------
		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//----------------------------------------------------------------
				

	}
	void CloseGdiPlus()
	{
		//--------------------------------------
		//gdi plus 종료코드 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}

	void printf(Graphics *grp,Font &font,Pen &pen,Brush &brush,  int x, int y, TCHAR *fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		grp->DrawString(szBuf, -1, &font, PointF(x, y), &brush);
		va_end(ap);
	}

	void printf(Graphics *grp, int x, int y, TCHAR *fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		
		Pen pen(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		FontFamily  fontFamily(L"굴림");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		grp->DrawString(szBuf, -1, &font, PointF(x, y), &brushBlack);

		va_end(ap);
	}
}