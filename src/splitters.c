/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifdef _USE_SPLITTER_FRAME

#include <windows.h>
#include "common.h"
#include "global_symbols.h"
#include "utils.h"
#include "res.h"

TCHAR szSpltWeClassName[] = TEXT ("SpltWe") ;
TCHAR szSpltNsClassName[] = TEXT ("SpltNs") ;

int we_sizing = 0;
int ns_sizing = 0;

static inline void send_splitter_x(HWND  hwnd, int pos)
{
    SendMessage(hwnd, WM_SPLITTER_X, pos, 0);
}

static inline void send_splitter_y(HWND  hwnd, int pos)
{
    SendMessage(hwnd, WM_SPLITTER_Y, pos, 0);
}


#define    MIN_SPLT_SPACE    (100)

void WINAPI DrawXorBar(HDC hdc, int x1, int y1, int width, int height)
{
static WORD _dotPatternBmp[8] = 
{ 
0x00aa, 0x0055, 0x00aa, 0x0055, 
0x00aa, 0x0055, 0x00aa, 0x0055
};

HBITMAP hbitmap;
HBRUSH hbrush,hbrushOld;

hbitmap = CreateBitmap(8,8,1,1,_dotPatternBmp);
hbrush = CreatePatternBrush(hbitmap);

SetBrushOrgEx(hdc,x1,y1,0);

hbrushOld = (HBRUSH)SelectObject(hdc,hbrush);

PatBlt(hdc,x1,y1,width,height,PATINVERT);

SelectObject(hdc,hbrushOld);

DeleteObject(hbrush);
DeleteObject(hbitmap);
} 

LRESULT CALLBACK SpltWe_WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
static int  oldx;
static int y;
static int line_height;
static int min_left;
static int max_right;
POINT pt;
HDC hdc;
RECT rect;
HWND hp = GetParent(hwnd);



    
    switch (message)
    {
        case WM_CREATE:

            return 0 ;

case WM_LBUTTONDOWN:
    SetCapture(hwnd);
    we_sizing = 1;
    line_height = win_height(hwnd);
    y = win_top(hwnd);;
pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

GetWindowRect(hp,&rect);
min_left = rect.left + MIN_SPLT_SPACE;
max_right = rect.right - MIN_SPLT_SPACE;
//GetClientRect(hwnd,&splt_rect);
//SCreenToClient(rect);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;

ClientToScreen(hwnd,&pt);


//convert the mouse coordinates relative to the top-left of
//the window
//ScreenToClient(hwnd_frame,&pt);

if(pt.x < min_left) pt.x = min_left;
if(pt.x > max_right) 
{
    pt.x = max_right;
}


hdc = GetDC(NULL);
DrawXorBar(hdc, pt.x, y, SPLT_WIDTH, line_height);
ReleaseDC(NULL, hdc);

oldx = pt.x;

break;

case WM_LBUTTONUP:
    ReleaseCapture();

pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

GetClientRect(hp,&rect);
//GetClientRect(hwnd,&splt_rect);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;

hdc = GetDC(NULL);
DrawXorBar(hdc, oldx, y, SPLT_WIDTH, line_height);
ReleaseDC(NULL, hdc);


we_sizing = 0;
pt.x = oldx;
ScreenToClient(hp,&pt);
send_splitter_x(hp, pt.x);
break;

case WM_MOUSEMOVE:
if(0==we_sizing)  break;

pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

//GetClientRect(hwnd_frame,&rect);
//GetClientRect(hwnd,&splt_rect);
//SCreenToClient(rect);
ClientToScreen(hwnd,&pt);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;


//convert the mouse coordinates relative to the top-left of
//the window
//ScreenToClient(hwnd_frame,&pt);

if(pt.x < min_left) pt.x = min_left;
if(pt.x > max_right) 
{
    pt.x = max_right;
}




if(pt.x != oldx && wParam & MK_LBUTTON)
{
hdc = GetDC(NULL);
DrawXorBar(hdc, oldx, y, SPLT_WIDTH, line_height);
DrawXorBar(hdc, pt.x, y, SPLT_WIDTH, line_height);
ReleaseDC(NULL, hdc);

oldx = pt.x;
}

break;

}
    
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}

LRESULT CALLBACK SpltNs_WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
static int  oldy;
static int x;
static int line_width;
static int min_top;
static int max_bottom;
POINT pt;
HDC hdc;
RECT rect;

HWND hp = GetParent(hwnd);

    
    switch (message)
    {
        case WM_CREATE:

            return 0 ;

case WM_LBUTTONDOWN:
    SetCapture(hwnd);
    ns_sizing = 1;
    line_width = win_width(hwnd);
    x = win_left(hwnd);;
pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

GetWindowRect(hp,&rect);
min_top= win_top(hp)+ MIN_SPLT_SPACE;
max_bottom = win_bottom(hp) - MIN_SPLT_SPACE;
//GetClientRect(hwnd,&splt_rect);
//SCreenToClient(rect);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;

ClientToScreen(hwnd,&pt);


//convert the mouse coordinates relative to the top-left of
//the window
//ScreenToClient(hwnd_frame,&pt);

if(pt.y < min_top) pt.y = min_top;
if(pt.y > max_bottom) 
{
    pt.y = max_bottom;
}


hdc = GetDC(NULL);
DrawXorBar(hdc, x, pt.y, line_width, SPLT_WIDTH);
ReleaseDC(NULL, hdc);

oldy = pt.y;

break;

case WM_LBUTTONUP:
    ReleaseCapture();

pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

GetClientRect(hp,&rect);
//GetClientRect(hwnd,&splt_rect);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;

hdc = GetDC(NULL);
DrawXorBar(hdc, x, oldy, line_width, SPLT_WIDTH);
ReleaseDC(NULL, hdc);


ns_sizing = 0;
pt.y = oldy;
ScreenToClient(hp,&pt);
send_splitter_y(hp, pt.y);
break;

case WM_MOUSEMOVE:
if(0==ns_sizing)  break;

pt.x = (short)LOWORD(lParam);  // horizontal position of cursor 
pt.y = (short)HIWORD(lParam);

//GetClientRect(hwnd_frame,&rect);
//GetClientRect(hwnd,&splt_rect);
//SCreenToClient(rect);
ClientToScreen(hwnd,&pt);

//GetWindowRect(hwnd_frame, &rect_frame_scr);
//client_0_0.x = 0;
//client_0_0.y=0;
//ClientToScreen(hwnd_frame,&client_0_0);
//client_0_0.y-= rect_frame_scr.top;
//client_0_0.x-= rect_frame_scr.left;


//convert the mouse coordinates relative to the top-left of
//the window
//ScreenToClient(hwnd_frame,&pt);

if(pt.y < min_top) pt.y = min_top;
if(pt.y > max_bottom) 
{
    pt.y = max_bottom;
}




if(pt.y != oldy && wParam & MK_LBUTTON)
{
hdc = GetDC(NULL);
DrawXorBar(hdc, x, oldy, line_width, SPLT_WIDTH);
DrawXorBar(hdc, x, pt.y, line_width, SPLT_WIDTH);
ReleaseDC(NULL, hdc);

oldy = pt.y;
}

break;

}
    
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}

int register_splt_wins()
{
    WNDCLASS    sub_wndclass;
    sub_wndclass.style      = CS_HREDRAW | CS_VREDRAW;
    sub_wndclass.lpfnWndProc= SpltWe_WndProc;
    sub_wndclass.cbClsExtra = 0;
    sub_wndclass.cbWndExtra = 0;
    sub_wndclass.hInstance  = g_hInstance;
    sub_wndclass.hCursor    = LoadCursor (NULL, IDC_SIZEWE);
    sub_wndclass.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);
    sub_wndclass.lpszMenuName   = NULL;
    sub_wndclass.lpszClassName  = szSpltWeClassName;


    if (!RegisterClass (&sub_wndclass))
     {
        MessageBox (NULL, TEXT ("Program requires Windows NT!"),
          szAppName, MB_ICONERROR) ;
        return FAIL;
     }

    sub_wndclass.style      = CS_HREDRAW | CS_VREDRAW;
    sub_wndclass.lpfnWndProc= SpltNs_WndProc;
    sub_wndclass.cbClsExtra = 0;
    sub_wndclass.cbWndExtra = 0;
    sub_wndclass.hInstance  = g_hInstance;
    sub_wndclass.hCursor    = LoadCursor (NULL, IDC_SIZENS);
    sub_wndclass.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);
    sub_wndclass.lpszMenuName   = NULL;
    sub_wndclass.lpszClassName  = szSpltNsClassName;


    if (!RegisterClass (&sub_wndclass))
     {
        MessageBox (NULL, TEXT ("Program requires Windows NT!"),
          szAppName, MB_ICONERROR) ;
        return FAIL;
     }

    return SUCCESS;

}


#endif





