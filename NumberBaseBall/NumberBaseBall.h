
// NumberBaseBall.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CNumberBaseBallApp:
// �� Ŭ������ ������ ���ؼ��� NumberBaseBall.cpp�� �����Ͻʽÿ�.
//

class CNumberBaseBallApp : public CWinApp
{
public:
	CNumberBaseBallApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CNumberBaseBallApp theApp;