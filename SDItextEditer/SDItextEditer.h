
// SDItextEditer.h : SDItextEditer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSDItextEditerApp:
// �йش����ʵ�֣������ SDItextEditer.cpp
//

class CSDItextEditerApp : public CWinApp
{
public:
	CSDItextEditerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDItextEditerApp theApp;
