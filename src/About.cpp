// About.cpp : implementation file
//

#include "stdafx.h"
#include "QueryPosition.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// About dialog


About::About(CWnd* pParent /*=NULL*/)
	: CDialog(About::IDD, pParent)
{
	//{{AFX_DATA_INIT(About)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void About::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(About)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(About, CDialog)
	//{{AFX_MSG_MAP(About)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// About message handlers

BOOL About::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText(IDC_EDIT_ABOUT,"你好，我是计算机学院的余涛，我常用Vic___这个称呼。“陈政”同学主要负责数据的收集整理，而我写了这个程序。\r\n如果你想交流和提出意见，请访问这个小软件的开源地址：\r\nhttps://github.com/Vic020/QueryPosition。你可以直接修改代码，然后向主仓库提出合并。\r\n对了，按ESC退出");	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
