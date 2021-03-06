// exam4.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "exam4.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM4));

    MSG msg;

    // 기본 메시지 루프입니다.
	plusEngine::GDIPLUS_Loop(msg, Rect(0, 0, 320, 240));

    return (int) msg.wParam;
}

GameObject g_ObjMissile;
GameObject *g_ObjMissiles[1024];
int g_nMissileCount;
Image *g_pImgMissile;

void OnCreate(HWND hWnd)
{
	g_ObjMissile.m_fRotation = 0.0;
	g_ObjMissile.m_fSpeed = 0.0;
	g_ObjMissile.m_position = irr::core::vector2df(0, 0);
	g_pImgMissile = g_ObjMissile.m_pImg = new Image(L"../../res/spr_missile.png");

	for (int i = 0; i < 1024; i++) {
		g_ObjMissiles[i] = NULL;
	}
	g_nMissileCount = 0;
}

void OnApply(double fDelta)
{
	GameObject_Apply(&g_ObjMissile, fDelta);
	for (int i = 0; i < 1024; i++) {
		if (g_ObjMissiles[i]) {
			GameObject_Apply(g_ObjMissiles[i],fDelta);
			if (g_ObjMissiles[i]->m_nFSM == 20) {
				delete g_ObjMissiles[i];
				g_ObjMissiles[i] = NULL;
			}
		}
	}
}

void OnRender(double fDelta,Graphics *grp)
{
	grp->Clear(Color(200, 191, 231));
	Pen pen(Color(0, 0, 0));
	grp->DrawLine(&pen, 0, 120, 320, 120);
	grp->DrawLine(&pen, 160, 0, 160, 240);
	grp->DrawRectangle(&pen, 0, 0, 320, 240);
	grp->SetTransform(&Matrix(1, 0, 0, 1, 160, 120));
	GameObject_Draw(&g_ObjMissile, *grp);

	for (int i = 0; i < 1024; i++) {
		if (g_ObjMissiles[i]) {
			GameObject_Draw(g_ObjMissiles[i], *grp);
		}
	}

	grp->ResetTransform();
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM4);
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {case WM_LBUTTONDOWN:
	{
		int mx = LOWORD(lParam);
		int my = HIWORD(lParam);
		g_ObjMissile.m_position.set(mx-160, my-120);
		for (int i = 0; i < 1024; i++) {
			if (g_ObjMissiles[i] == NULL) {
				GameObject * pObj = (GameObject *)malloc(sizeof(GameObject));
				pObj->m_nFSM = 0;
				pObj->m_pImg = g_pImgMissile;
				pObj->m_fRotation = 0.0;
				pObj->m_fSpeed = 10.0;
				pObj->m_fFuel = 5.0;
				pObj->m_position = irr::core::vector2df(mx - 160, my - 120);
				g_ObjMissiles[i] = pObj;
				break;
			}
		}
	}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
			g_ObjMissile.m_fSpeed += 10.0;
			break;
		case VK_LEFT:
			g_ObjMissile.m_fSpeed -= 10.0;
			break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
			case IDM_START:
			{
				OnCreate(hWnd);
				plusEngine::fpOnLoop = OnApply;
				plusEngine::fpOnRender = OnRender;
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.


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
