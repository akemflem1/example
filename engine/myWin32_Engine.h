namespace mywin32_engine 
{
	namespace util {
		//, �� ���е� ���ڿ��� �Ǽ��� �迭�� �ٲ��ִ� �Լ�, ��ȯ���� ������ �Ǽ��� ����
		int Buffer2DoubleArray(TCHAR *szBuf, double *pResult) {
			int nCount = 0;
			TCHAR *pwc;
			pwc = wcstok(szBuf, L", ");
			pResult[nCount++] = _wtof(pwc);
			while (pwc != NULL) {
				pwc = wcstok(NULL, L", ");
				if (pwc != NULL) {
					pResult[nCount++] = _wtof(pwc);
				}
			}
			return nCount;
		}
	}
	HANDLE makeTextBox(HWND hWnd, int nPosX, int nPosY, int nWidth, int nHeight, int nHandle)
	{
		return CreateWindow(L"static",L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, nPosX, nPosY, nWidth, nHeight, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	HANDLE makeMiniEditBox(HWND hWnd, int nPosX, int nPosY, int nHandle)
	{
		return CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	HANDLE makeEditBox(HWND hWnd, int nPosX, int nPosY, int nWidth, int nHandle)
	{
		return CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, nPosX, nPosY, nWidth, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	HANDLE makeSimpleButton(HWND hWnd, TCHAR *pszText, int nPosX, int nPosY, int nHandle)
	{
		return CreateWindow(L"button", pszText, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	int GetControlValueInt(HWND hWnd, int nId)
	{
		TCHAR szBuf[256];
		GetWindowText(GetDlgItem(hWnd, nId), szBuf, 256);
		return _wtoi(szBuf);
	}

	void SetControlValueInt(HWND hWnd, int nId, int nValue)
	{
		TCHAR szBuf[256];
		swprintf(szBuf, 256, L"%d", nValue);
		SetWindowText(GetDlgItem(hWnd, nId), szBuf);
	}

	double GetControlValueDouble(HWND hWnd, int nId)
	{
		TCHAR szBuf[256];
		GetWindowText(GetDlgItem(hWnd, nId), szBuf, 256);
		return _wtoi(szBuf);
	}

	void SetControlValueDouble(HWND hWnd, int nId, double nValue)
	{
		TCHAR szBuf[256];
		swprintf(szBuf, 256, L"%lf", nValue);
		SetWindowText(GetDlgItem(hWnd, nId), szBuf);
	}
}