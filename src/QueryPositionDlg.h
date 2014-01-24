// QueryPositionDlg.h : header file
//

#if !defined(AFX_QUERYPOSITIONDLG_H__9C7226F5_4FE0_4FAD_8A76_AA68EA37098B__INCLUDED_)
#define AFX_QUERYPOSITIONDLG_H__9C7226F5_4FE0_4FAD_8A76_AA68EA37098B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQueryPositionDlg dialog

class CQueryPositionDlg : public CDialog
{
// Construction
public:
	CQueryPositionDlg(CWnd* pParent = NULL);	// standard constructor
	void AddAllData();
// Dialog Data
	//{{AFX_DATA(CQueryPositionDlg)
	enum { IDD = IDD_QUERYPOSITION_DIALOG };
	CComboBox	m_combo_cities;
	CComboBox	m_combo_counties;
	CComboBox	m_combo_provinces;
	CListBox	m_list_result;
	CEdit	m_edit_result;
	CEdit	m_edit_find;
	CButton	m_check_top;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryPositionDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQueryPositionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckTop();
	virtual void OnOK();
	afx_msg void OnChangeEditFind();
	afx_msg void OnSelchangeListResult();
	afx_msg void OnDblclkListResult();
	afx_msg void OnSelchangeComboProvinces();
	afx_msg void OnSelchangeComboCities();
	afx_msg void OnSelchangeComboCounties();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuitemUplog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYPOSITIONDLG_H__9C7226F5_4FE0_4FAD_8A76_AA68EA37098B__INCLUDED_)
