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
	v1_0.Format("V1.0	 2014年1月21日	By Vic \r\n 1.软件发布\r\n 2.加入行政分区数据\r\n 3.加入模糊查找功能\r\n");
	//1.1
	CString v1_1;
	v1_1.Format("V1.1	 2014年1月22日	By Vic \r\n 1.修复 广东省深圳市宝安区BUG \r\n 2.加入关于和升级日志界面\r\n");

	//version info
	version_info = v1_1 + v1_0;

	SetDlgItemText(IDC_EDIT_UPLOG,version_info);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
