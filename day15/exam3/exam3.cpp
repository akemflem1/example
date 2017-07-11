// exam3.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "exam3.h"
#include "tilemap.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK procTileSelDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK procTileScriptDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	//----------------------------------------------------------------------
	//gdi plus 초기화 코드 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//-----------------------------------------------------------------------

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM3));

    MSG msg;

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	//--------------------------------------
	//gdi plus 종료코드 
	GdiplusShutdown(gdiplusToken);
	//--------------------------------------

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
S_GAMEMAP g_GameMap;
int g_nCurrentTileIndex;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		g_nCurrentTileIndex = 1;
		InitMap(&g_GameMap, 8, 8, L"../../res/loveable_rogue.png", 16, 16);
		SetTilePosition(&g_GameMap, 0, 177, 0);
		SetTilePosition(&g_GameMap, 16, 177, 1);
		SetTilePosition(&g_GameMap, 16 * 2, 177, 2);
		SetTilePosition(&g_GameMap, 16 * 3, 177, 3);
	}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
			case IDM_SCRIPT:
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_SCRIPT), hWnd, procTileScriptDlg);
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
			case IDM_TILE_SEL:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_SELECT_TILE), hWnd, procTileSelDlg);
				break;
			case IDM_SAVE:
			{
				FILE *fp;
				fp = fopen("save.bin", "wb");

				fwrite(&g_GameMap, 264, 1, fp);

				fclose(fp);
			}
			break;
			case IDM_LOAD:
			{
				FILE *fp;
				fp = fopen("save.bin", "rb");

				fread(&g_GameMap, 264, 1, fp);

				fclose(fp);
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_LBUTTONDOWN:
	{
		int mx = LOWORD(lParam);
		int my = HIWORD(lParam);
		TCHAR szBuf[256];
		swprintf(szBuf,L"%d, %d \n", mx / g_GameMap.m_TileWidth, my / g_GameMap.m_TileHeight);
		OutputDebugString(szBuf);

		if (mx < 128 && my < 128) {
			SetMapIndex(&g_GameMap,	mx / g_GameMap.m_TileWidth, my / g_GameMap.m_TileHeight, g_nCurrentTileIndex);
		}
		else if (my < 16 && mx > 144) {
			swprintf(szBuf, L"%d \n", mx / g_GameMap.m_TileWidth);
			OutputDebugString(szBuf);
			g_nCurrentTileIndex = (mx / g_GameMap.m_TileWidth) - 8;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
			Graphics grp(hdc);
			//DrawTile(&g_GameMap, &grp, 0, 0, 1);
			DrawMap(&g_GameMap, &grp, 0, 0);
			Pen penBlack(Color(255, 0, 0, 0));
			grp.DrawRectangle(&penBlack, Rect(0, 0, 128, 128));

			DrawTilePalette(&g_GameMap, &grp, 9, 0);

			//현제 선택된 타일 표시 
			grp.TranslateTransform(160, 32);
			grp.ScaleTransform(4, 4);
			DrawTile(&g_GameMap, &grp, 0, 0, g_nCurrentTileIndex - 1);

			grp.ResetTransform();
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK procTileSelDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			TCHAR szBuf[64];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_SELTILE), szBuf, 64);

			g_nCurrentTileIndex = _wtoi(szBuf);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)FALSE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK procTileScriptDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			TCHAR szBuf[64];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_SCRIPT), szBuf, 64);

			TCHAR *token;
			token = wcstok(szBuf, L", ");

			//SetMapIndex
			if (!wcscmp(L"smi", token)) {
				int x, y, idx;
				token = wcstok(NULL, L", ");
				x = _wtoi(token);
				token = wcstok(NULL, L", ");
				y = _wtoi(token);
				token = wcstok(NULL, L", ");
				idx = _wtoi(token);
				SetMapIndex(&g_GameMap, x, y, idx);

			}
			else if (!wcscmp(L"stp", token)) {
				int x, y, idx;
				token = wcstok(NULL, L", ");
				x = _wtoi(token);
				token = wcstok(NULL, L", ");
				y = _wtoi(token);
				token = wcstok(NULL, L", ");
				idx = _wtoi(token);
				SetTilePosition(&g_GameMap, x, y, idx);
			}
			else if (!wcscmp(L"dtl", token)) {
				//DrawTile(&g_GameMap,pGrp, int x, int y, int nTileIndex)
			}
			else {
				MessageBox(hDlg, L"존재하지않는 스크립트입니다.", L"", MB_OK);
			}


			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)FALSE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}