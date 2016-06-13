
// MapiMuleII.h : main header file for the MapiMuleII application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMapiMuleIIApp:
// See MapiMuleII.cpp for the implementation of this class
//

class CMapiMuleIIApp : public CWinAppEx
{
public:
	CMapiMuleIIApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMapiMuleIIApp theApp;
