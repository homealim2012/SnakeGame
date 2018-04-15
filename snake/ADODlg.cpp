// ADODlg.cpp : implementation file
//

#include "stdafx.h"
#include "贪吃蛇.h"
#include "ADODlg.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODlg dialog

int CADODlg::Num_AfxOleInit=0;
CADODlg::CADODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADODlg)
	m_date = _T("");
	m_length = 0;
	m_ID=-1;
	select_pos=-1;
	open_num = 0;
	//}}AFX_DATA_INIT
}


void CADODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADODlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_date);
	DDX_Text(pDX, IDC_EDIT2, m_length);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADODlg, CDialog)
	//{{AFX_MSG_MAP(CADODlg)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonDel)
	ON_BN_CLICKED(IDOK, OnLoad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODlg message handlers

BOOL CADODlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetDate();
	UpdateData(false);//变量到对话框
	UpdateData(true);//对话框到变量
	if(Num_AfxOleInit==0)
	{
	  ::AfxOleInit();
      Num_AfxOleInit++;
	}
	// TODO: Add extra initialization here
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"编号",LVCFMT_LEFT,50,0);
	m_Grid.InsertColumn(1,"时间",LVCFMT_LEFT,90,0);
	m_Grid.InsertColumn(2,"食物位置",LVCFMT_LEFT,80,1);
	m_Grid.InsertColumn(3,"蛇长",LVCFMT_LEFT,46,2);
	if(AddToGrid())
	  return TRUE;  // return TRUE unless you set the focus to a control
	else return FALSE;             // EXCEPTION: OCX Property Pages should return FALSE
}

void CADODlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	// TODO: Add your message handler code here
}

int CADODlg::OnInitADOConn()
{
    try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		CString strConnect="DRIVER={Microsoft Access Driver (*.mdb)};uid=;pwd=;DBQ=.\\snake.mdb;";
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
	return true;
   //AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

void CADODlg::ExitConnect()
{
   if(m_pRecordset!=NULL)
         m_pRecordset->Close();
   m_pConnection->Close();
}

int CADODlg::AddToGrid()
{
   if(!OnInitADOConn())
   {
	   return false;
   }
   _bstr_t bstrSQL="select * from save order by ID";
   m_pRecordset.CreateInstance(_uuidof(Recordset));
   m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),
   adOpenDynamic,adLockOptimistic,adCmdText);
   while(!m_pRecordset->adoEOF)
   {
	   m_Grid.InsertItem(0,"");
       m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("ID"));
	   m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("时间"));
       m_Grid.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("食物位置"));
	   m_Grid.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("蛇长"));
       m_pRecordset->MoveNext();
   }
   ExitConnect();
   return true;
}

void CADODlg::setdata(string s_food, string s_snake,int length)
{
    this->s_food=s_food;
	this->m_length=length;
	this->s_snake=s_snake;
}

void CADODlg::SetDate()
{
    time_t nowtime; 
    struct tm *timeinfo; 
	time( &nowtime ); 
	timeinfo = localtime( &nowtime ); 
	year = timeinfo->tm_year + 1900; 
	month = timeinfo->tm_mon + 1; 
	day = timeinfo->tm_mday;
	m_date.Format(_T("%d-%d-%d"),year,month,day);
}

void CADODlg::OnButtonSave() 
{
	if(m_length==0)// TODO: Add your control notification handler code here
	{
		MessageBox("当前游戏未运行!");
        return;
	}
	else 
	{
       if(!OnInitADOConn())
	   {
	      return;
	   }
	   else
	   {
		if(open_num==0)
		{
         CString sql;
	     const char *chr;
	     chr = s_snake.c_str();
	     CString m_snake(chr);
         chr = s_food.c_str();
	     CString m_food(chr);
	     string d="";
	     d+=direction;
         chr = d.c_str();
	     CString m_direction(chr);
	     sql.Format("insert into save(时间,食物位置,蛇长,蛇的位置,方向) values('%s','%s',%d,'%s','%s')"
		   ,m_date,m_food,m_length,m_snake,m_direction);
	     m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
         m_pConnection->Close();
		 open_num++;
	     m_Grid.DeleteAllItems();
	     AddToGrid();
		}
		else 
		{
          MessageBox("已经保存游戏进度!");
          return;
		}
	   }
	}
}

void CADODlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
      select_pos=m_Grid.GetSelectionMark();
    m_ID=_ttol(m_Grid.GetItemText(select_pos,0));
	*pResult = 0;
}

void CADODlg::OnButtonDel() 
{
	 if(select_pos==-1)
	 {
      MessageBox("没有选中对象!");
	  return;
	 }
     if(!OnInitADOConn())
	 {
	      return;
	 }
	   else
	   {
         CString sql;
		 sql.Format("delete * from save where ID=%d",m_ID);
		 try
		 { 
            m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
            m_pConnection->Close();
		 }
		 catch(...)
		 {
			 MessageBox("删除失败");
			 return;
		 }
         MessageBox("删除成功");
		 open_num<=0 ? open_num=0 : open_num--;
		 select_pos=-1;
		 m_ID=-1;
	     m_Grid.DeleteAllItems();
	     AddToGrid();
	   }
	// TODO: Add your control notification handler code here	
}

void CADODlg::OnLoad() 
{
	 if(select_pos==-1)
	 {
      MessageBox("没有选中对象!");
	  return;
	 }// TODO: Add your control notification handler code here
	  if(!OnInitADOConn())
	  {
	    return;
	  }
	  else
	  {
         CString sql;
		 sql.Format("select * from save where ID=%d",m_ID);
		 try
		 { 
            m_pRecordset.CreateInstance(_uuidof(Recordset));
            m_pRecordset->Open((_bstr_t)sql,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
           while(!m_pRecordset->adoEOF)
		   {
             s_food=(char*)(_bstr_t)m_pRecordset->GetCollect("食物位置");
             s_snake=(char*)(_bstr_t)m_pRecordset->GetCollect("蛇的位置");
	         m_length=atoi((_bstr_t)m_pRecordset->GetCollect("蛇长"));
			 direction=*(char *)(_bstr_t)m_pRecordset->GetCollect("方向");
             m_pRecordset->MoveNext();
		   }
		 }
		 catch(...)
		 {
			 MessageBox("载入失败");
			 return;
		 }
         MessageBox("载入成功,请单击开始游戏");
		 EndDialog(IDOK);
	  }
}
