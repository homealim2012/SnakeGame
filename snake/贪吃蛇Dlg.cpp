// 贪吃蛇Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "贪吃蛇.h"
#include "贪吃蛇Dlg.h"
#include "HelpDialog.h"
#include "SpeedDialog.h"
#include "AboutDialog.h"
#include "ADODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void _random(int &x,int &y,SNAKE *s)
{
   int n=3*rand();
   x=n%(L_MAX)+1;y=n/(L_MAX)%(H_MAX)+1;
    snakedot *p=s->tail;
   while(p!=s->head)
   {
		   if(p->x==x && p->y==y) 
		   {
			   _random(x,y,s);
			   break;
		   }
		   else p=p->last;
	}
   if(p->x==x && p->y==y) _random(x,y,s);
}

char CMyDlg::getkey(char ch0)
{
    getkeylock.Lock();
	if(ch==LEFT)      {if(ch0==DOWN||ch0==UP)  ch0=ch;}
    else if(ch==RIGHT) {if(ch0==DOWN||ch0==UP)  ch0=ch;}
	else if(ch==UP) {if(ch0==LEFT||ch0==RIGHT)  ch0=ch;}
	else if(ch==DOWN) {if(ch0==LEFT||ch0==RIGHT)  ch0=ch;} 
	getkeylock.Unlock();
	return ch0;
}

void CMyDlg::gotoprintxy(int x,int y,int type)//????
 {
	//pDC=GetDC();
	//memDC->CreateCompatibleDC(pDC);
  //printlock.Lock();
  switch(type)
  {
   case DRAWFOOD:
   bmp->LoadBitmap(IDB_BITMAP_FOOD);//加载图片
   break;
   case DRAWSNAKE:
   bmp->LoadBitmap(IDB_BITMAP_SNAKE);//加载图片
   break;
   default:
   bmp->LoadBitmap(IDB_BITMAP_NULL); 
  }
  memDC->SelectObject(bmp);//选入设备描述表
   /*显示位图*/
  TransparentBlt(pDC->m_hDC,20*(x-1),20*(y-1),20,20,*memDC,0,0,20,20,RGB(255,255,255));
  bmp->DeleteObject();
  //printlock.Unlock();
  //pDC->BitBlt(point.x,j,28,29,&memDC,0,0,SRCCOPY);
  //显示一般位图
 }

int SNAKE::snakemove(char &ch0,FOOD &food)
	{ 
	   ch0=CMyDlg::getkey(ch0);
	   int X=head->x;
	   int Y=head->y;
       switch(ch0)
	   {
	       case UP:Y--;if(Y==0)return STOP;break;
           case DOWN:Y++;if(Y>H_MAX)return STOP;break;
           case LEFT:X--;if(X==0)return STOP;break;
	       case RIGHT:X++;if(X>L_MAX)return STOP;
	   }//??????
       snakedot *p=tail->last;
	   while(p!=head)
	   {
		   if(p->x==X && p->y==Y) return STOP;
		   else p=p->last;
	   }//?????????
	   if(food.meetfood(X,Y))
	   {
		   head->last=new snakedot(X,Y);
		   //printsnakedot(X,Y);
		   print=CPoint(X,Y);
		   head=head->last;
		   head->last=tail;
		   food.changefood(this);
		   length++;
	   }
	   else
	   {
	       //unprintsnakedot(tail->x,tail->y);
            unprint=CPoint(tail->x,tail->y);
	       //printsnakedot(X,Y);
			print=CPoint(X,Y);
           tail->x=X;tail->y=Y;
	       head=tail;tail=tail->last;
	   }
	   //????????
	   return RUN;
	}
/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
CSemaphore CMyDlg::getkeylock(1,1);
CSemaphore CMyDlg::game_state(0,1);
//CSemaphore CMyDlg::printlock(1,1);
CSemaphore CMyDlg::runlock(1,1);

UINT CMyDlg::gamerun(LPVOID pParam) 
{
	while(true)
	{
	   game_state.Lock();
	   current_state=r_state=INI;
	   snake=new SNAKE(ch0,m_direction,m_snake,m_length);
	   food=new FOOD(m_food);
       ::SendMessage(::AfxGetMainWnd()->m_hWnd,WM_MYONPAINT,0,0);
	   current_state=r_state=RUN;
	   ch=ch0;
	   Sleep(timenum);
       while(true) 
	   {
		   runlock.Lock();
		   current_state=snake->snakemove(ch0,*food);
		   runlock.Unlock();
		   if(r_state==STOP || current_state==STOP) break;
		   ::SendMessage(::AfxGetMainWnd()->m_hWnd,WM_MYONPAINT,0,0);
		   //发送部分重画的消息
		   Sleep(timenum);
	   }
	   delete snake;
	   delete food;
	   current_state=STOP;
	   r_state=STOP;
	 }
    return 0;
}
/*AfxBeginThread函数参数类型是UINT(usigned int)的。 
 而CreateThread函数的参数才是DWORD(unsigned long)
并且AfxBeginThread不需要指定为WINAPI回调函数*/


int CMyDlg::current_state=START;
int CMyDlg::r_state=START;
double CMyDlg::timenum=100;
char CMyDlg::ch=RIGHT;
char CMyDlg::ch0=RIGHT;
char CMyDlg::m_direction=RIGHT;

SNAKE * CMyDlg::snake=NULL;
FOOD * CMyDlg::food=NULL;
string CMyDlg::m_snake ="";
string CMyDlg::m_food  ="";
int    CMyDlg::m_length=0;

CDC * CMyDlg::pDC=NULL;
CBitmap * CMyDlg::bmp=new CBitmap;
CDC * CMyDlg::memDC=new CDC;


CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENUITEM_START, OnMenuitemStart)
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_CANCELMODE()
	ON_UPDATE_COMMAND_UI(IDB_MENU_PAUSE, OnUpdateMenuPause)
	ON_COMMAND(IDB_MENU_PAUSE, OnMenuPause)
	ON_COMMAND(ID_MENUITEM_HELP, OnMenuitemGameHelp)
	ON_COMMAND_RANGE(ID_MENUITEM_SLOW, ID_MENUITEM_FAST, OnMenuitemSpeed)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MENUITEM_SLOW, ID_MENUITEM_UD, OnUpdateMenuitemSpeed)
	ON_COMMAND(ID_MENUITEM_UD, OnMenuitemUd)
	ON_COMMAND(IDB_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	ON_COMMAND(IDB_MENU_READ, OnMenuRead)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_MESSAGE(WM_MYONPAINT,MyOnPaint)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_WM_CAPTURECHANGED()
	ON_WM_INITMENUPOPUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	// TODO: Add extra initialization here
	RECT rect;  
    GetWindowRect(&rect);//获得屏幕位置
	CRect Irect;
	GetClientRect(&Irect);//获得客户区的位置
	ClientToScreen(&Irect);//客户区转化成屏幕位置
	MoveWindow(rect.left,rect.top,Irect.left+800+rect.right-Irect.right,Irect.top+500+rect.bottom-Irect.bottom);
	pDC=GetDC(); //创建设备上下文
	m_pause=0;speed_choice=2;
	m_snake="";m_food="";
	m_length=0;
	runThread = AfxBeginThread(gamerun,NULL,THREAD_PRIORITY_NORMAL,0,0,NULL);//(位置？)
    memDC->CreateCompatibleDC(pDC);//创建位图控件
	//Invalidate(true);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
CRect CMyDlg::GetRect(CPoint point)
{
	return CRect(20*(point.x-1),20*(point.y-1),20*point.x,20*point.y);
}
void CMyDlg::MyOnPaint()
{
	/*****局部重绘****/
	if(current_state==RUN)
	{
	 CRect Ret[4];
	 Ret[0]=CRect(GetRect(snake->printsnakedot()));
	 Ret[1]=CRect(GetRect(snake->unprintsnakedot()));
	 for(int i=0;i<2;i++)
	 {
      InvalidateRect(Ret[i],true);
	 }
	 if(food->unprintfood()==food->printfood())
	 {
		Ret[2]=CRect(GetRect(food->unprintfood()));
        Ret[3]=CRect(GetRect(food->printfood()));  
		
			for(int i=2;i<4;i++)
			{
               InvalidateRect(Ret[i],true);
			}
	 }
	}
	if(current_state==INI)
	{
		Invalidate(true);
	}
}
void CMyDlg::OnPaint() 
{
	if(current_state==START)
	{
      SetBackground(IDB_BITMAP_ST);  
	}
	else
	{
        SetBackground(IDB_BITMAP_BAM);
		if(current_state==RUN)
		{
		 if(snake!=NULL && food!=NULL)
		 {
		  snake->printallsnake();
		  food->printfood();
		 }
		}
	}
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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(WaitForSingleObject(getkeylock,500)==WAIT_TIMEOUT)	
	{
		getkeylock.Unlock();
		return;
	}
	  ch=nChar;
      getkeylock.Unlock();
	  CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMyDlg::OnMenuitemStart() //开始游戏
{
	double temp_time=timenum;
	int response=0;
	if(current_state==RUN && runThread)//游戏结束状态情况？
	{
		response=MessageBox("需要重新开始吗?","贪吃蛇" ,MB_ICONQUESTION|MB_YESNO);
		if(response==IDNO)
			return;
		else
		{
			timenum=0;
			r_state=STOP;
		}
    }
	if(m_pause==true)
	{
		m_pause=false;
		runThread->ResumeThread();
	}	  
    timenum=temp_time;
    game_state.Unlock();// TODO: Add your command handler code here
}
void CMyDlg::SetBackground(int g)
{
    	/*****刷桌面背景****/
	    CPaintDC dc(this);
        CBitmap   bitmap;
        bitmap.LoadBitmap(g);    //这个IDB_BITMAP1要自己添加
        CBrush   brush;
        brush.CreatePatternBrush(&bitmap);
        CBrush*   pOldBrush   =   dc.SelectObject(&brush);
        dc.Rectangle(0,0,800,500);   // 这些参数可以调整图片添加位置和大小
        dc.SelectObject(pOldBrush);
	    bitmap.DeleteObject();
}
int CMyDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	RegisterHotKey(m_hWnd,15001,MOD_CONTROL,'S');
    RegisterHotKey(m_hWnd,15002,MOD_CONTROL,'s');
    RegisterHotKey(m_hWnd,'D',NULL,VK_RIGHT);
    RegisterHotKey(m_hWnd,'A',NULL,VK_LEFT);
    RegisterHotKey(m_hWnd,'W',NULL,VK_UP);
    RegisterHotKey(m_hWnd,'S',NULL,VK_DOWN);
    RegisterHotKey(m_hWnd,10000,NULL,VK_RETURN);
	RegisterHotKey(m_hWnd,10001,NULL,VK_ESCAPE);
	// TODO: Add your specialized creation code here	
	return 0;
}

void CMyDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	UnregisterHotKey(m_hWnd, 15001);
    UnregisterHotKey(m_hWnd, 15002);
	UnregisterHotKey(m_hWnd, 'D');
    UnregisterHotKey(m_hWnd, 'A');
	UnregisterHotKey(m_hWnd, 'W');
    UnregisterHotKey(m_hWnd, 'S');
    UnregisterHotKey(m_hWnd, 10000);
	UnregisterHotKey(m_hWnd, 10001);
	// TODO: Add your message handler code here	
}

void CMyDlg::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here	
	CDialog::OnCaptureChanged(pWnd);
}

LRESULT CMyDlg::OnHotKey(WPARAM wParam,LPARAM lParam)
{
	if(WaitForSingleObject(getkeylock,500)==WAIT_TIMEOUT)	
	{
		getkeylock.Unlock();
		return 0;
	}
    if (wParam== 15001||wParam == 15002)
    {
       CMyDlg::OnMenuPause();
    }
	else if(wParam=='A' || wParam=='S' || wParam=='D'  || wParam=='W')
	ch=wParam;
	getkeylock.Unlock();
    return 0;
}

void CMyDlg::OnKillFocus(CWnd* pNewWnd) 
{
	CDialog::OnKillFocus(pNewWnd);
	 runThread->SuspendThread();
	 OnDestroy();//失去焦点时应该取消热键，防止键盘上某些键无法正常使用
	 // TODO: Add your message handler code here       
}
void CMyDlg::OnSetFocus(CWnd* pNewWnd) 
{
	CDialog::OnSetFocus(pNewWnd);
	runThread->ResumeThread();// TODO: Add your message handler code here
	OnCreate(NULL);
}
void CMyDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	// TODO: Add your message handler code here	
}
void CMyDlg::OnUpdateMenuPause(CCmdUI* pCmdUI) 
{
	if(current_state==RUN)
	{
	  pCmdUI->Enable(true);
      if(m_pause==1)
	    pCmdUI->SetText("继续");
	  else pCmdUI->SetText("暂停");
	}
    else
	{
      pCmdUI->Enable(false);
	}
	// TODO: Add your command handler code here	
}
void CMyDlg::OnMenuPause() 
{
	m_pause=!m_pause;
	if(m_pause==true)
	{
	  WaitForSingleObject(runlock,500);
	  runThread->SuspendThread();
	  runlock.Unlock();
	}
	else
	{    
	  runThread->ResumeThread();// TODO: Add your command update UI handler code here
	}
}
void CMyDlg::OnMenuRead() 
{
	CADODlg dlg;
	if(current_state==RUN)
	{
	  if(WaitForSingleObject(runlock,500)==WAIT_TIMEOUT)
	  {
		  MessageBox("载入失败!");
	      dlg.setdata("");
	  }
	  else
	  {
		  dlg.direction=ch0;
	      dlg.setdata(food->foodsave(),snake->snakesave(),snake->length);
	  }
	  runlock.Unlock();
	}
	else dlg.setdata("");
	// TODO: Add your command handler code here
	if(dlg.DoModal()==IDOK)
	{
		m_direction=dlg.direction;
        m_length=dlg.m_length;
		m_snake=dlg.s_snake;
		m_food=dlg.s_food;
	}
}
void CMyDlg::OnMenuitemGameHelp() 
{
      CHelpDialog dlg;   // 对话框类对象                 
	  dlg.DoModal(); // TODO: Add your command handler code here	
}
void CMyDlg::OnMenuitemSpeed(UINT nID) //设置速度
{
   speed_choice= nID - ID_MENUITEM_SLOW +1;
	timenum=200-speed_choice*50;
}
void CMyDlg::OnMenuitemUd() 
{
	CSpeedDialog dlg;   // 对话框类对象
	dlg.m_time=timenum;
	dlg.m_time_s=timenum;
	if(dlg.DoModal()== IDOK)
	{
	  timenum=dlg.m_time;// TODO: Add your command handler code here
	  speed_choice=4;
	}
}
void CMyDlg::OnUpdateMenuitemSpeed(CCmdUI* pCmdUI) 
{
	if(pCmdUI->m_nID-ID_MENUITEM_SLOW==speed_choice-1)
      pCmdUI->SetCheck(true);
	else pCmdUI->SetCheck(false);
	// TODO: Add your command update UI handler code here	
}
void CMyDlg::OnMenuExit() 
{
	AfxGetMainWnd()->SendMessage(WM_CLOSE); // TODO: Add your command handler code here
}
void CMyDlg::OnMenuitemAbout() 
{
	CAboutDialog dlg;// TODO: Add your command handler code here
	dlg.DoModal();
}
BOOL CMyDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::PreTranslateMessage(pMsg);
}
void CMyDlg::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	// TODO: Add your specialized code here and/or call the base class
	CDialog::CalcWindowRect(lpClientRect, nAdjustType);
}
//解决了对话框不能响应ON_UPDATE_COMMAND_UI的消息
void CMyDlg::OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu)
 {
     ASSERT(pPopupMenu != NULL);
     // Check the enabled state of various menu items.

    CCmdUI state;
     state.m_pMenu = pPopupMenu;
     ASSERT(state.m_pOther == NULL);
     ASSERT(state.m_pParentMenu == NULL);

    // Determine if menu is popup in top-level menu and set m_pOther to
     // it if so (m_pParentMenu == NULL indicates that it is secondary popup).
     HMENU hParentMenu;
     if (AfxGetThreadState()->m_hTrackingMenu == pPopupMenu->m_hMenu)
         state.m_pParentMenu = pPopupMenu;    // Parent == child for tracking popup.
     else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
     {
         CWnd* pParent = this;
            // Child Windows don't have menus--need to go to the top!
         if (pParent != NULL &&
            (hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
         {
            int nIndexMax = ::GetMenuItemCount(hParentMenu);
            for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
            {
             if (::GetSubMenu(hParentMenu, nIndex) == pPopupMenu->m_hMenu)
             {
                 // When popup is found, m_pParentMenu is containing menu.
                 state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
                 break;
             }
            }
         }
     }

    state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
     for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
       state.m_nIndex++)
     {
         state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
         if (state.m_nID == 0)
            continue; // Menu separator or invalid cmd - ignore it.

        ASSERT(state.m_pOther == NULL);
         ASSERT(state.m_pMenu != NULL);
         if (state.m_nID == (UINT)-1)
         {
            // Possibly a popup menu, route to first item of that popup.
            state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
            if (state.m_pSubMenu == NULL ||
             (state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
             state.m_nID == (UINT)-1)
            {
             continue;       // First item of popup can't be routed to.
            }
            state.DoUpdate(this, TRUE);   // Popups are never auto disabled.
         }
         else
         {
            // Normal menu item.
            // Auto enable/disable if frame window has m_bAutoMenuEnable
            // set and command is _not_ a system command.
            state.m_pSubMenu = NULL;
            state.DoUpdate(this, FALSE);
         }

        // Adjust for menu deletions and additions.
         UINT nCount = pPopupMenu->GetMenuItemCount();
         if (nCount < state.m_nIndexMax)
         {
            state.m_nIndex -= (state.m_nIndexMax - nCount);
            while (state.m_nIndex < nCount &&
             pPopupMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
            {
             state.m_nIndex++;
            }
         }
         state.m_nIndexMax = nCount;
     }
 }






