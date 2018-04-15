; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ã∞≥‘…ﬂ.h"

ClassCount=6
Class1=CMyApp
Class2=CMyDlg

ResourceCount=7
Resource2=IDD_DIALOG_SPEED
Resource1=IDR_MAINFRAME
Resource3=IDD_HELP
Class3=CHelpDialog
Resource4=IDD_DIALOG_ABOUT
Class4=CSpeedDialog
Resource5=IDD_MY_DIALOG
Class5=CAboutDialog
Resource6=IDD_DIALOG_DATA
Class6=CADODlg
Resource7=IDR_MENU1

[CLS:CMyApp]
Type=0
HeaderFile=Ã∞≥‘…ﬂ.h
ImplementationFile=Ã∞≥‘…ﬂ.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=Ã∞≥‘…ﬂDlg.h
ImplementationFile=Ã∞≥‘…ﬂDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM_UD



[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=0

[MNU:IDR_MENU1]
Type=1
Class=CMyDlg
Command1=ID_MENUITEM_START
Command2=IDB_MENU_PAUSE
Command3=IDB_MENU_READ
Command4=IDB_MENU_EXIT
Command5=ID_MENUITEM_SLOW
Command6=ID_MENUITEM_MEDIUM
Command7=ID_MENUITEM_FAST
Command8=ID_MENUITEM_UD
Command9=ID_MENUITEM_HELP
Command10=ID_MENUITEM_ABOUT
CommandCount=10

[DLG:IDD_HELP]
Type=1
Class=CHelpDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CHelpDialog]
Type=0
HeaderFile=HelpDialog.h
ImplementationFile=HelpDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CHelpDialog

[DLG:IDD_DIALOG_SPEED]
Type=1
Class=CSpeedDialog
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SLIDER1,msctls_trackbar32,1342242840
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[CLS:CSpeedDialog]
Type=0
HeaderFile=SpeedDialog.h
ImplementationFile=SpeedDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CSpeedDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_ABOUT]
Type=1
Class=CAboutDialog
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[CLS:CAboutDialog]
Type=0
HeaderFile=AboutDialog.h
ImplementationFile=AboutDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CAboutDialog

[DLG:IDD_DIALOG_DATA]
Type=1
Class=CADODlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350633877
Control4=IDC_EDIT1,edit,1350633600
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT2,edit,1350633600
Control10=IDC_BUTTON1,button,1342242816
Control11=IDC_BUTTON2,button,1342242816

[CLS:CADODlg]
Type=0
HeaderFile=ADODlg.h
ImplementationFile=ADODlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

