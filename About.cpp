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
	
	SetDlgItemText(IDC_EDIT_ABOUT,"��ã����Ǽ����ѧԺ�����Σ��ҳ���Vic___����ƺ�����������ͬѧ��Ҫ�������ݵ��ռ���������д���������\r\n������뽻��������������������С����Ŀ�Դ��ַ��\r\nhttps://github.com/Vic020/QueryPosition�������ֱ���޸Ĵ��룬Ȼ�������ֿ�����ϲ���\r\n���ˣ���ESC�˳�");	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
