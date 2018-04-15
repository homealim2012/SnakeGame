#if !defined(AFX_SPEEDDIALOG_H__C3BD29D9_124D_40E7_81D3_52356EFA850E__INCLUDED_)
#define AFX_SPEEDDIALOG_H__C3BD29D9_124D_40E7_81D3_52356EFA850E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpeedDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpeedDialog dialog

class CSpeedDialog : public CDialog
{
// Construction
public:
	CSpeedDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpeedDialog)
	enum { IDD = IDD_DIALOG_SPEED };
	CSliderCtrl	m_speed_s;
	int		m_time_s;
	int		m_time;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeedDialog)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpeedDialog)
	afx_msg void OnChangeEdit1();
	afx_msg void OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEEDDIALOG_H__C3BD29D9_124D_40E7_81D3_52356EFA850E__INCLUDED_)
