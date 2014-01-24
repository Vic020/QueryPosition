#if !defined(AFX_UPLOG_H__CB5951C4_29D3_45EF_BDE5_EF329448765F__INCLUDED_)
#define AFX_UPLOG_H__CB5951C4_29D3_45EF_BDE5_EF329448765F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UpLog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// UpLog dialog

class UpLog : public CDialog
{
// Construction
public:
	UpLog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(UpLog)
	enum { IDD = IDD_DIALOG_UPLOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UpLog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(UpLog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPLOG_H__CB5951C4_29D3_45EF_BDE5_EF329448765F__INCLUDED_)
