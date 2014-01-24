// QueryPositionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QueryPosition.h"
#include "QueryPositionDlg.h"
#include "data.h"
#include "About.h"
#include "UpLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryPositionDlg dialog

	Data* data = new Data();


CQueryPositionDlg::CQueryPositionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryPositionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryPositionDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQueryPositionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryPositionDlg)
	DDX_Control(pDX, IDC_COMBO_CITIES, m_combo_cities);
	DDX_Control(pDX, IDC_COMBO_COUNTIES, m_combo_counties);
	DDX_Control(pDX, IDC_COMBO_PROVINCES, m_combo_provinces);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_edit_result);
	DDX_Control(pDX, IDC_EDIT_FIND, m_edit_find);
	DDX_Control(pDX, IDC_CHECK_TOP, m_check_top);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQueryPositionDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryPositionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_TOP, OnCheckTop)
	ON_EN_CHANGE(IDC_EDIT_FIND, OnChangeEditFind)
	ON_LBN_SELCHANGE(IDC_LIST_RESULT, OnSelchangeListResult)
	ON_LBN_DBLCLK(IDC_LIST_RESULT, OnDblclkListResult)
	ON_CBN_SELCHANGE(IDC_COMBO_PROVINCES, OnSelchangeComboProvinces)
	ON_CBN_SELCHANGE(IDC_COMBO_CITIES, OnSelchangeComboCities)
	ON_CBN_SELCHANGE(IDC_COMBO_COUNTIES, OnSelchangeComboCounties)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	ON_COMMAND(ID_MENUITEM_UPLOG, OnMenuitemUplog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryPositionDlg message handlers

BOOL CQueryPositionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	SkinH_AttachResEx(MAKEINTRESOURCE(IDR_SHE1),_T("SHE"),_T(""),0,0,0);
	
	for(int i=0; i < data->listcsa.GetSize(); i++)	//初始化结果list框中的数据
	{
		m_list_result.AddString(data->listcsa.GetAt(i));
	}
	
	//初始化省份

	CString tempstring;
	CString comparestring;
	//第一省份 节省一个判断
	tempstring = data->listcsa.GetAt(0);
	comparestring = tempstring.Mid(7) ;
	m_combo_provinces.AddString(comparestring);

	for(i=1; i < data->listcsa.GetSize(); i++)
	{
		tempstring = data->listcsa.GetAt(i);
		if (tempstring.Find(comparestring)==-1)
		{
			comparestring = tempstring.Mid(7) ;
			m_combo_provinces.AddString(comparestring);
		}
	}
	SetDlgItemText(IDC_COMBO_PROVINCES,"省");
	SetDlgItemText(IDC_COMBO_CITIES,"市");
	SetDlgItemText(IDC_COMBO_COUNTIES,"县/区");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQueryPositionDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQueryPositionDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQueryPositionDlg::OnCheckTop() 
{
	int state = m_check_top.GetCheck();
	if(state == 1) //没有被选中
	{
		SetWindowPos(&CWnd::wndTopMost,10,10,10,10,SWP_NOMOVE|SWP_NOSIZE);
	}
	else
	{
		SetWindowPos(&CWnd::wndNoTopMost,10,10,10,10,SWP_NOMOVE|SWP_NOSIZE);
	}
}

void CQueryPositionDlg::OnOK() 
{
	exit(0);
//	CDialog::OnOK();
}

BOOL CQueryPositionDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN) 
	{
		
		switch(pMsg->wParam)
		{
		case VK_RETURN: //回车
			return TRUE;
		case VK_ESCAPE: //ESC
			return TRUE;
		}
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

void CQueryPositionDlg::OnChangeEditFind() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	int flag = 1; //标记是否找到数据

	int length = m_list_result.GetCount();
	
	while(length--)
	{
		m_list_result.DeleteString(length);
	}
	if(m_edit_find.GetWindowTextLength == 0)
	{
		for(int i=0; i < data->listcsa.GetSize(); i++)
		{
			m_list_result.AddString(data->listcsa.GetAt(i));
			flag = 0;
		}
	}
	CString findstring ;
	CString tempstring ;
	m_edit_find.GetWindowText(findstring);
	int findresult;
	for(int i=0; i < data->listcsa.GetSize(); i++)
	{
		tempstring = data->listcsa.GetAt(i);
		findresult = tempstring.Find(findstring);
		if(findresult != -1)
		{
			m_list_result.AddString(tempstring);
			flag = 0;
		}
	}
	if(flag)
	{
		findstring = "没有“" + findstring + "”数据";
		m_list_result.AddString(findstring);
	}

}

void CQueryPositionDlg::OnSelchangeListResult() 
{
	CString resultstring ;
	m_list_result.GetText(m_list_result.GetCurSel(),resultstring);
	m_edit_result.SetWindowText(resultstring);
}

void CQueryPositionDlg::OnDblclkListResult() 
{
	if(OpenClipboard())
	{
		CString resultstring ;
		CString tempstring ;
		m_list_result.GetText(m_list_result.GetCurSel(),resultstring);
		resultstring = resultstring.Left(6);
		EmptyClipboard();
		HANDLE hClip;
		hClip = GlobalAlloc(GMEM_MOVEABLE,resultstring.GetLength()+1);
		char *pBuf;
		pBuf=(char *)GlobalLock(hClip);//锁定全局内存中指定的内存块，并返回一个地址值，令其指向内存块的起始处
		strcpy(pBuf,resultstring);//将Str对象中的数据Copy到内存空间中
		GlobalUnlock(hClip);//解锁全局内存块
		SetClipboardData(CF_TEXT,hClip);//设置剪贴板数据
		CloseClipboard();//关闭
		tempstring = "已复制地区号“" + resultstring + " ”"; 
		MessageBox(tempstring,"提示",MB_OK);
	}
}

void CQueryPositionDlg::OnSelchangeComboProvinces() 
{

	//清空数据
	int length = m_list_result.GetCount();
	
	while(length--)
	{
		m_list_result.DeleteString(length);
	}
	SetDlgItemText(IDC_COMBO_CITIES,"市");
	length = m_combo_cities.GetCount();
	while(length--)
	{
		m_combo_cities.DeleteString(length);
	}
	SetDlgItemText(IDC_COMBO_COUNTIES,"县/区");
	length = m_combo_counties.GetCount();
	while(length--)
	{
		m_combo_counties.DeleteString(length);
	}
	//显示省份结果
	CString findstring ;
	CString tempstring ;
	int findresult ;
	m_combo_provinces.GetLBText(m_combo_provinces.GetCurSel(),findstring);
	for(int i=0; i < data->listcsa.GetSize(); i++)
	{
		tempstring = data->listcsa.GetAt(i);
		findresult = tempstring.Find(findstring);
		if(findresult != -1)
		{
			m_list_result.AddString(tempstring);
		}
	}
	
	

	//加载城市

	CString comparestring;
	//第一城市 节省一个判断
	m_list_result.GetText(1,tempstring);
	
	int comparepos = 7 + findstring.GetLength();

	comparestring = tempstring.Mid(comparepos) ;

	m_combo_cities.AddString(comparestring);

	for(i=2; i< m_list_result.GetCount() ;i++ )
	{
		m_list_result.GetText(i,tempstring);
		if(tempstring.Find(comparestring)==-1)
		{
			comparestring = tempstring.Mid(comparepos) ;
			m_combo_cities.AddString(comparestring);
		}
	}
	m_combo_cities.SetCurSel(0);
}

void CQueryPositionDlg::OnSelchangeComboCities() 
{
	//清空数据
	int length = m_list_result.GetCount();
	
	while(length--)
	{
		m_list_result.DeleteString(length);
	}


	SetDlgItemText(IDC_COMBO_COUNTIES,"县/区");
	length = m_combo_counties.GetCount();
	while(length--)
	{
		m_combo_counties.DeleteString(length);
	}
	//显示城市结果
	CString findstring ;
	CString tempstring ;
	int findresult ;
	m_combo_cities.GetLBText(m_combo_cities.GetCurSel(),findstring);
	m_combo_provinces.GetLBText(m_combo_provinces.GetCurSel(),tempstring);
	findstring = tempstring + findstring;
	for(int i=0; i < data->listcsa.GetSize(); i++)
	{
		tempstring = data->listcsa.GetAt(i);
		findresult = tempstring.Find(findstring);
		if(findresult != -1)
		{
			m_list_result.AddString(tempstring);
		}
	}

	//加载县城
	CString comparestring;
	//第一城市 节省一个判断
	m_list_result.GetText(1,tempstring);
	
	int comparepos = 7 + findstring.GetLength();

	comparestring = tempstring.Mid(comparepos) ;

	m_combo_counties.AddString(comparestring);

	for(i=2; i< m_list_result.GetCount() ;i++ )
	{
		m_list_result.GetText(i,tempstring);
		if(tempstring.Find(comparestring)==-1)
		{
			comparestring = tempstring.Mid(comparepos) ;
			m_combo_counties.AddString(comparestring);
		}
	}
	m_combo_counties.SetCurSel(0);

}

void CQueryPositionDlg::OnSelchangeComboCounties() 
{
	//清空数据
	int length = m_list_result.GetCount();
	
	while(length--)
	{
		m_list_result.DeleteString(length);
	}
		//显示城市结果
	CString findstring ;
	CString tempstring ;
	int findresult ;
	m_combo_cities.GetLBText(m_combo_cities.GetCurSel(),findstring);
	m_combo_provinces.GetLBText(m_combo_provinces.GetCurSel(),tempstring);
	findstring = tempstring + findstring;
	m_combo_counties.GetLBText(m_combo_counties.GetCurSel(),tempstring);
	findstring = findstring + tempstring ;
	for(int i=0; i < data->listcsa.GetSize(); i++)
	{
		tempstring = data->listcsa.GetAt(i);
		findresult = tempstring.Find(findstring);
		if(findresult != -1)
		{
			m_list_result.AddString(tempstring);
		}
	}

}




void CQueryPositionDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CMenu menu,*rpop;
	menu.LoadMenu(IDR_MENU_RPOP);
	rpop=menu.GetSubMenu(0);
	GetCursorPos(&point);
	rpop->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	CDialog::OnRButtonDown(nFlags, point);
}

void CQueryPositionDlg::OnMenuitemAbout() 
{
	About about;
	about.DoModal();
}

void CQueryPositionDlg::OnMenuitemUplog() 
{
	UpLog uplog;
	uplog.DoModal();
	
}
