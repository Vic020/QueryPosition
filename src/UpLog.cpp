// UpLog.cpp : implementation file
//

#include "stdafx.h"
#include "QueryPosition.h"
#include "UpLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UpLog dialog


UpLog::UpLog(CWnd* pParent /*=NULL*/)
	: CDialog(UpLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(UpLog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void UpLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UpLog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UpLog, CDialog)
	//{{AFX_MSG_MAP(UpLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UpLog message handlers

BOOL UpLog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString version_info;

	//1.0
	CString v1_0;
	v1_0.Format("V1.0	 2014��1��21��	By Vic \r\n 1.�������\r\n 2.����������������\r\n 3.����ģ�����ҹ���\r\n");
	//1.1
	CString v1_1;
	v1_1.Format("V1.1	 2014��1��22��	By Vic \r\n 1.�޸� �㶫ʡ�����б�����BUG \r\n 2.������ں�������־����\r\n");

	//version info
	version_info = v1_1 + v1_0;

	SetDlgItemText(IDC_EDIT_UPLOG,version_info);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
