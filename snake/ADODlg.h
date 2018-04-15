#if !defined(AFX_ADODLG_H__97593C98_A22E_4F85_BAA4_FCA3FB96CB6A__INCLUDED_)
#define AFX_ADODLG_H__97593C98_A22E_4F85_BAA4_FCA3FB96CB6A__INCLUDED_
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADODlg.h : header file
//
#include<string>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CADODlg dialog

class CADODlg : public CDialog
{
// Construction
public:
	long m_ID;
	char direction;
	void SetDate();
	string s_food;
	string s_snake;
	void setdata(string s_food="",string s_snake="",int length=0);
	int AddToGrid();
	void ExitConnect();
	int OnInitADOConn();
	CADODlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CADODlg)
	enum { IDD = IDD_DIALOG_DATA };
	CListCtrl	m_Grid;
	CString	m_date;
	int		m_length;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int static Num_AfxOleInit;
    _ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	int year,month,day;
	// Generated message map functions
	//{{AFX_MSG(CADODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnButtonSave();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonDel();
	afx_msg void OnLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	long select_pos;
	int open_num;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODLG_H__97593C98_A22E_4F85_BAA4_FCA3FB96CB6A__INCLUDED_)
