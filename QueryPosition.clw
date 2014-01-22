; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=About
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QueryPosition.h"

ClassCount=4
Class1=CQueryPositionApp
Class2=CQueryPositionDlg

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_QUERYPOSITION_DIALOG
Class3=About
Resource3=IDD_DIALOG_UPLOG
Resource4=IDD_DIALOG_ABOUT
Class4=UpLog
Resource5=IDR_MENU_RPOP

[CLS:CQueryPositionApp]
Type=0
HeaderFile=QueryPosition.h
ImplementationFile=QueryPosition.cpp
Filter=N
LastObject=CQueryPositionApp

[CLS:CQueryPositionDlg]
Type=0
HeaderFile=QueryPositionDlg.h
ImplementationFile=QueryPositionDlg.cpp
Filter=D
LastObject=CQueryPositionDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_QUERYPOSITION_DIALOG]
Type=1
Class=CQueryPositionDlg
ControlCount=13
Control1=IDC_EDIT_FIND,edit,1350631808
Control2=IDC_COMBO_PROVINCES,combobox,1344339970
Control3=IDC_COMBO_CITIES,combobox,1344339970
Control4=IDC_COMBO_COUNTIES,combobox,1344339970
Control5=IDC_EDIT_RESULT,edit,1350631552
Control6=IDC_CHECK_TOP,button,1342242819
Control7=IDC_LIST_RESULT,listbox,1352728835
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342177294
Control13=IDOK,button,1342242817

[DLG:IDD_DIALOG_ABOUT]
Type=1
Class=About
ControlCount=2
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_ABOUT,edit,1352728580

[CLS:About]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D
LastObject=About
VirtualFilter=dWC

[MNU:IDR_MENU_RPOP]
Type=1
Class=CQueryPositionApp
Command1=ID_MENUITEM_UPLOG
Command2=ID_MENUITEM_ABOUT
CommandCount=2

[DLG:IDD_DIALOG_UPLOG]
Type=1
Class=UpLog
ControlCount=1
Control1=IDC_EDIT_UPLOG,edit,1344342148

[CLS:UpLog]
Type=0
HeaderFile=UpLog.h
ImplementationFile=UpLog.cpp
BaseClass=CDialog
Filter=D
LastObject=UpLog
VirtualFilter=dWC

