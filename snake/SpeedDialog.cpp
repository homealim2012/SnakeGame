// SpeedDialog.cpp : implementation file
//

#include "stdafx.h"
#include "贪吃蛇.h"
#include "SpeedDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpeedDialog dialog


CSpeedDialog::CSpeedDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSpeedDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpeedDialog)
	m_time_s = 100;
	m_time = m_time_s;
	//}}AFX_DATA_INIT
}


void CSpeedDialog::DoDataExchange(CDataExchange* pDX)
{
	
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeedDialog)
	DDX_Control(pDX, IDC_SLIDER1, m_speed_s);
	DDX_Slider(pDX, IDC_SLIDER1, m_time_s);
	DDX_Text(pDX, IDC_EDIT1, m_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpeedDialog, CDialog)
	//{{AFX_MSG_MAP(CSpeedDialog)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER1, OnOutofmemorySlider1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeedDialog message handlers

void CSpeedDialog::OnChangeEdit1() 
{
	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_time_s=m_time;
	m_speed_s.SetPos(m_time);
    //UpdateArea();
	UpdateData(false);

}

void CSpeedDialog::OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_time=m_time_s;
	UpdateData(false);
	*pResult = 0;
}
BOOL CSpeedDialog::OnInitDialog()
{

	 //m_time=m_time_s;
	CDialog::OnInitDialog();
	m_speed_s.SetRange(30,200);
	 m_speed_s.SetPos(m_time);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpeedDialog::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_time=m_time_s;
	UpdateData(false);
	*pResult = 0;
}

void CSpeedDialog::OnOK() 
{
	// TODO: Add extra validation here
	if(m_time_s>=30 && m_time_s<=200)
	{
	    //CMyDlg::timenum=m_time;
	    CDialog::OnOK();
	}
	else
	{
		MessageBox("停歇时间应为30ms到200ms之间","自定义速度");
		return;
	}
}
