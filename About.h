#if !defined(AFX_ABOUT_H__1CC049FE_1359_4F47_BB09_4B2485FE5DFE__INCLUDED_)
#define AFX_ABOUT_H__1CC049FE_1359_4F47_BB09_4B2485FE5DFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// About.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// About dialog

class About : public CDialog
{
// Construction
public:
	About(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(About)
	enum { IDD = IDD_DIALOG_ABOUT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(About)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(About)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUT_H__1CC049FE_1359_4F47_BB09_4B2485FE5DFE__INCLUDED_)
