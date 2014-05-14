// SameGameProject.h : main header file for the SameGameProject application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "stdafx.h"


// CSameGameProjectApp:
// See SameGameProject.cpp for the implementation of this class
//

class CSameGameProjectApp : public CWinApp
{
public:
	CSameGameProjectApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSameGameProjectApp theApp;