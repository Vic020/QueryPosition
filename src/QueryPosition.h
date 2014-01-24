// QueryPosition.h : main header file for the QUERYPOSITION application
//

#if !defined(AFX_QUERYPOSITION_H__A03172E3_B054_43B6_8D2A_6395E28B10B0__INCLUDED_)
#define AFX_QUERYPOSITION_H__A03172E3_B054_43B6_8D2A_6395E28B10B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQueryPositionApp:
// See QueryPosition.cpp for the implementation of this class
//

class CQueryPositionApp : public CWinApp
{
public:
	CQueryPositionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryPositionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQueryPositionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYPOSITION_H__A03172E3_B054_43B6_8D2A_6395E28B10B0__INCLUDED_)
