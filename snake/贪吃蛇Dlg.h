#pragma once
// 贪吃蛇Dlg.h : header file
//
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <afxmt.h> 
#include <stdlib.h>
#include <string>
using namespace std;
#if !defined(AFX_DLG_H__7B72A8A2_09E0_49D7_B283_8406A73D08BC__INCLUDED_)
#define AFX_DLG_H__7B72A8A2_09E0_49D7_B283_8406A73D08BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog


/**********************************************************************************/
const UNDRAW=3331001;
const DRAWSNAKE=3331002;
const DRAWFOOD=3331003;
const LIVE=2221001;
const DEAD=2221000;
const RUN=1;
const STOP=0;
const START=2;
const INI=3;
const L_MAX=40;
const H_MAX=25;
const UP='W';//10003;//'W';//72;
const DOWN='S';//10004;//'S';//80;
const LEFT='A';//10002;//'A';//75;
const RIGHT='D';//10001;//'D';//77;
const WM_MYONPAINT= WM_USER+100;
/*******************************************************************************/
/**************************????************************************************/
class SNAKE;
class FOOD;
class snakedot;
extern void _random(int &x,int &y,SNAKE *s);//全局函数在cpp中定义，防止重复链接，在h文件中声明
class CMyDlg : public CDialog
{
// Construction
public:
	void SetBackground(int);
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
    static	UINT  gamerun(LPVOID pParam);
	char static getkey(char ch0);
	void static gotoprintxy(int x,int y,int type);//????
	CRect GetRect(CPoint);
	void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);
    ~CMyDlg()
	{		
	       memDC->DeleteDC();
           pDC->DeleteDC();
		   //CloseHandle(gamerun); 
	}
// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    static CSemaphore getkeylock;
	//static CSemaphore printlock;
    static CSemaphore game_state;
	static CSemaphore runlock;
    CWinThread* runThread;

	char static ch0,ch;
    char static m_direction;
	int speed_choice;
	double static timenum;
	int static current_state;
	int static r_state;
    bool m_pause;

	CDC static *memDC,*pDC;
	CBitmap static *bmp;

	SNAKE static *snake;
	FOOD static *food;
	string static m_snake;
	string static m_food;
	int static m_length;
    
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void MyOnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuitemStart();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pNewWnd);
	afx_msg void OnCancelMode();
	afx_msg void OnUpdateMenuPause(CCmdUI* pCmdUI);
	afx_msg void OnMenuPause();
	afx_msg void OnMenuitemGameHelp();
	afx_msg void OnMenuitemSpeed(UINT nID);
	afx_msg void OnMenuitemUd();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuRead();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
    afx_msg LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnUpdateMenuitemSpeed(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class FOOD
{
private:
    int x,y;
	CPoint unprint;
	CPoint print;
public:
FOOD(string &m_food)
{
	if(m_food=="")
	{
	  srand(time(NULL));
	  do
	  {
	   int n=3*rand();
	   x=n%(L_MAX-1)+1;y=n/(L_MAX-1)%(H_MAX-1)+1;
	  }while((x==3||x==4||x==5)&&y==10);
	}
	else
	{
		int t=0;
		for(int i=0;i<m_food.length();i++)
		{ 
           if(m_food[i]==',')
		   {
			 x=t;
             t=0;
		   }
		   else
		   {
             t=t*10+m_food[i]-'0';
		   }
		}
		y=t;
        m_food="";
	}
	//printfood(x,y);
}
int meetfood(int X,int Y)
{
    if(x==X && y==Y) return 1;
	else return 0;
}
void changefood(SNAKE *s)
{
	unprint=CPoint(x,y);
	_random(x,y,s);
	print=CPoint(x,y);
	//printfood(x,y);
}
CPoint unprintfood()
{
	return unprint;
}
CPoint printfood(int x,int y)
{
	CMyDlg::gotoprintxy(x,y,DRAWFOOD);
	return print;
}
CPoint printfood()
{
    CMyDlg::gotoprintxy(x,y,DRAWFOOD);
	return print;
}
string foodsave()
{
	char X[7],Y[7];
	itoa(x,X,10);
	itoa(y,Y,10);
   return string(X)+","+string(Y);
}
};
class snakedot
{
 public:
	int x,y;
	snakedot *last;
    snakedot(int X,int Y=10):x(X),y(Y){}
    snakedot(){}
};
class SNAKE
{
private:
	snakedot *head,*tail;
    CPoint unprint;
	CPoint print;
public:
	int length;
	friend void _random(int &x,int &y,SNAKE *s);
	friend void FOOD::changefood(SNAKE *);
	SNAKE(char &ch0,char &m_direction,string &m_snake,int &m_length)
	{
	   if(m_length==0)
	   {
	     head=new snakedot(4);
	     tail=new snakedot(2);
	     tail->last=new snakedot(3);
	     tail->last->last=head;
	     head->last=tail;
	     length=3;ch0=RIGHT;
		 //unprint=Point(2,10);
		 //print=Point(4,10);
	   }
	   else
	   {
		 length=m_length;
         snakedot *p;
         int temp_x=0,temp_y=0,temp_t=0;
		 int num=0;
		 ch0=m_direction;
         for(int i=1;i<m_snake.length();i++)
		{ 
           if(m_snake[i]==',')
		   {
			 temp_x=temp_t;
             temp_t=0;
		   }
		   else if(m_snake[i]=='#')
		   { 
              /*
              temp_y=temp_t;
			  p=new snakedot(temp_x,temp_y);
			  if(num==0)
			  {
                  tail=p;
			  }
			  if(num==m_length-1)
			  {
                  head=p;
			  }
			  num++;p=p->last;
              temp_x=temp_y=temp_t=0;
		   }
		   else
		   {
             temp_t=temp_t*10+m_snake[i]-'0';
		   }*/
			  temp_y=temp_t;
			  if(num==0)
			  {
                  p=tail=new snakedot(temp_x,temp_y);
			  }
			  if(num==m_length-1)
			  {
                  p->last=new snakedot(temp_x,temp_y);
				  //p=p->last;
                  head=p;
			  }
			  else
			  {
                p->last=new snakedot(temp_x,temp_y);
				p=p->last;
			  }
			  num++;
              temp_x=temp_y=temp_t=0;
		   }
		   else
		   {
             temp_t=temp_t*10+m_snake[i]-'0';
		   }
		}
        m_snake="";
        m_length=0;
		p->last=tail;
		m_direction='D';
	   }
	   //printallsnake();
	}
	int snakemove(char &ch0,FOOD &food);
	void printallsnake()
	{
	  snakedot *p=tail;
	  while(p!=head)
	  {
		CMyDlg::gotoprintxy(p->x,p->y,DRAWSNAKE);
        p=p->last;
	  }
       CMyDlg::gotoprintxy(p->x,p->y,DRAWSNAKE);
	}
    CPoint printsnakedot()
	{
	   return print;
	}
    CPoint unprintsnakedot(int x=0,int y=0)
	{
		return unprint;
	}
	string snakesave()
	{
	  string s_snake="#";
	  snakedot *p=tail;
      char X[7],Y[7]; 
	  while(p!=head)
	  {
		itoa(p->x,X,10);
		itoa(p->y,Y,10);
	    s_snake+=string(X)+","+string(Y)+"#";
        p=p->last;
	  }
	    itoa(p->x,X,10);
		itoa(p->y,Y,10);//
	    s_snake+=string(X)+","+string(Y)+"#";
		return s_snake;
	}
	~SNAKE()
	{
		snakedot *p;
        while(tail!=head)
		{
			p=tail;
            tail=tail->last;
            delete p;
		}
		delete tail;
	}
};

/**************************??????************************************************/


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__7B72A8A2_09E0_49D7_B283_8406A73D08BC__INCLUDED_)
