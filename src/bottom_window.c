/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */
 
#include <windows.h>
#include <time.h>

#include "common.h"
#include "global_symbols.h"
#include "res.h"

TCHAR szBottomWinClassName[] = TEXT ("bottom_win") ;
HWND    hwnd_bottom;

HWND  hwnd_button_bottom_close;
#if 0
HWND    hwnd_b_we_splitter;
int     b_we_pos;

HWND    hwnd_b2_tab;
HWND    hwnd_b2_tab1;

TCHAR *tab_b2_icons[] = {TEXT("info_icon")};
TCHAR *tab_b2_labels[] = {TEXT("��Ϣ")};

HWND    hwnd_b_tab;
HWND    hwnd_b_tab1;
TCHAR sz_bTab1WinClassName[] = TEXT ("tab1_win") ;

TCHAR *tab_b_icons[] = {TEXT("stats_icon")};
TCHAR *tab_b_labels[] = {TEXT("ͳ��")};
int err_cnt, info_cnt;
#endif

LRESULT CALLBACK bottom_WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc ;
    PAINTSTRUCT ps ;
    HWND    hwnd_sub ;
    RECT		rect ;
    int cxClient, cyClient;
    int tab_height;
    
static HMENU	hMenu ;
    POINT point ;
    
    switch (message)
    {
        case WM_CREATE:
            hwnd_bottom = hwnd;
            hwnd_button_bottom_close =	CreateWindow ( TEXT("button"),TEXT("X"),
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 20, 30, 30,
    hwnd, (HMENU)ID_BUTTON_BOTTOM_CLOSE,
               g_hInstance, NULL) ;
#if 0
           hwnd_b_we_splitter = CreateWindow (szSpltWeClassName, TEXT ("sub win"),
                WS_CHILD|WS_VISIBLE,
                SPLT_WIDTH,   point.y,  SPLT_WIDTH, SPLT_WIDTH,
                hwnd, NULL, g_hInstance, NULL) ;
;
#if 1
            hwnd_b_tab=DoCreateTabControl(g_hInstance, hwnd_bottom
                ,WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | TCS_BOTTOM
                , ARRAY_SIZE(tab_b_icons), tab_b_icons, tab_b_labels);
#else
            hwnd_b_tab=DoCreateFlatTabControl(g_hInstance, hwnd_bottom
                ,szFlatTabWinClassName
                , ARRAY_SIZE(tab_b_labels), tab_b_labels);
#endif
            hwnd_b_tab1=create_tab_win(g_hInstance, hwnd_bottom, szStatsWinClassName, WS_CHILD | WS_VISIBLE | WS_BORDER);

            hwnd_b2_tab=DoCreateTabControl(g_hInstance, hwnd_bottom
                ,WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE | TCS_BOTTOM
                , ARRAY_SIZE(tab_b2_icons), tab_b2_icons, tab_b2_labels);

            hwnd_b2_tab1=create_tab_win(g_hInstance, hwnd_bottom, TEXT("edit")
                , WS_CHILD | WS_BORDER | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE|ES_AUTOVSCROLL|ES_WANTRETURN);
            return 0 ;

        case WM_SPLITTER_X:
        {
            b_we_pos=wParam;
            resize_window(hwnd);
            return 0 ;
        }
#endif
        case WM_SIZE:

      		cxClient = LOWORD (lParam) ;
      		cyClient = HIWORD (lParam) ;


            MoveWindow	(hwnd_button_bottom_close, 	cxClient-25, 0,
                25, 25, TRUE) ;
#if 0

            MoveWindow	(hwnd_b_tab, 	0, 0,
                b_we_pos-SPLT_WIDTH, cyClient, TRUE) ;
            GetClientRect(hwnd_b_tab,&rect);
            TabCtrl_AdjustRect(hwnd_b_tab, FALSE, &rect); 

            MoveWindow(hwnd_b_tab1, 	0, 0,
                b_we_pos-SPLT_WIDTH, rect.bottom-rect.top, TRUE) ;
            MoveWindow	(hwnd_b_tab, 	0, cyClient-flat_tab_height,
                cxClient-25, flat_tab_height, TRUE) ;

            MoveWindow(hwnd_b_tab1, 	0, 0,
                cxClient-25, cyClient-flat_tab_height, TRUE) ;
            MoveWindow(hwnd_b_tab2, 	0, 0,
                cxClient-25, cyClient-flat_tab_height, TRUE) ;


      	    MoveWindow	(hwnd_b_we_splitter, 	b_we_pos-SPLT_WIDTH,
                            0,
                  			SPLT_WIDTH, cyClient, TRUE) ;

            MoveWindow	(hwnd_b2_tab, 	b_we_pos, 0,
                cxClient-b_we_pos-25, cyClient, TRUE) ;
            GetClientRect(hwnd_b2_tab,&rect);
            TabCtrl_AdjustRect(hwnd_b2_tab, FALSE, &rect); 

            MoveWindow(hwnd_b2_tab1, 	b_we_pos, 0,
                cxClient-b_we_pos-25, rect.bottom-rect.top, TRUE) ;
#endif

            return 0 ;

            
        case 	WM_COMMAND:
            switch (LOWORD(wParam))
            {
                  
                case    ID_BUTTON_BOTTOM_CLOSE:
                    SetFocus(hwnd_right);
       				SendMessage(hwnd_frame, WM_COMMAND, MAKEWPARAM(IDM_APP_BOTTOM_WIN, 0),0);
       				return 0 ;
             }
            break;


    }
    
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}

int register_bottom_win()
{
    WNDCLASS    sub_wndclass;
    sub_wndclass.style      = CS_HREDRAW | CS_VREDRAW;
    sub_wndclass.lpfnWndProc= bottom_WndProc;
    sub_wndclass.cbClsExtra = 0;
    sub_wndclass.cbWndExtra = 0;
    sub_wndclass.hInstance  = g_hInstance;
    sub_wndclass.hIcon      = LoadIcon (g_hInstance, TEXT("my_frame_icon"));
    sub_wndclass.hCursor    = LoadCursor (NULL, IDC_ARROW);
    sub_wndclass.hbrBackground  = (HBRUSH)CreateSolidBrush(GetSysColor(COLOR_ACTIVECAPTION));
    sub_wndclass.lpszMenuName   = NULL;
    sub_wndclass.lpszClassName  = szBottomWinClassName;


    if (!RegisterClass (&sub_wndclass))
     {
        MessageBox (NULL, TEXT ("Program requires Windows NT!"),
          szAppName, MB_ICONERROR) ;
        return FAIL;
     }

    return SUCCESS;

}

#if 0
void edit_append_text(HWND hwnd, TCHAR   *szBuffer)
{
    int ndx = GetWindowTextLength (hwnd);
    SendMessage (hwnd, EM_SETSEL, (WPARAM)ndx, (LPARAM)ndx);
    SendMessage (hwnd, EM_REPLACESEL, 0, (LPARAM) ((LPSTR) szBuffer));

}

void WriteInfo(TCHAR * szFormat, ...)
{
	TCHAR   szBuffer [1024] ;
	va_list pArgList ;
    int len1, len2;
    time_t log_time = time(NULL);

    len1 = strftime(szBuffer,  sizeof(szBuffer), "[%Y%m%d %H:%M:%S]: ", localtime(&log_time));

	va_start (pArgList, szFormat) ;

	// The last argument to wvsprintf points to the arguments

	len2=_vsntprintf (	szBuffer+len1, sizeof (szBuffer) / sizeof (TCHAR), 
			szFormat, pArgList) ;

	// The va_end macro just zeroes out pArgList for no good reason
	va_end (pArgList) ;
    szBuffer[len1 + len2] = '\r';
    szBuffer[len1 + len2 + 1] = '\n';
    szBuffer[len1 + len2 + 2] = '\0';
    
    edit_append_text(hwnd_b2_tab1, szBuffer);

}

void PrintText(TCHAR * szFormat, ...)
{
	TCHAR   szBuffer [1024] ;
	va_list pArgList ;
    int len;

	va_start (pArgList, szFormat) ;

	// The last argument to wvsprintf points to the arguments

	len=_vsntprintf (	szBuffer, sizeof (szBuffer) / sizeof (TCHAR), 
			szFormat, pArgList) ;

	// The va_end macro just zeroes out pArgList for no good reason
	va_end (pArgList) ;
    //szBuffer[len]='\r';
    //szBuffer[len+1]='\n';
    //szBuffer[len+2]=0;
    
    edit_append_text(hwnd_b2_tab1, szBuffer);

}

void print_mem(void *start_addr, uint32_t length)
{
    char str_addr[32];
    char str_data[64];
    char str_readable[32];
    unsigned char *cur_pos = start_addr;
    int i;

    while (length >= 16)
    {
        sprintf(str_addr, "%-16lx", (unsigned long)(void *)cur_pos);
        for (i = 0; i < 16; i++)
        {
            sprintf(str_data + i*3, "%02hhx ", cur_pos[i]);
            if (cur_pos[i] > 31 &&  cur_pos[i] < 127)
            sprintf(str_readable + i, "%c", (char)(cur_pos[i]));
            else
            sprintf(str_readable + i, "%c", '*');
        }
        length -= 16;
        cur_pos += 16;
        PrintText("%s: %s: %s\r\n", str_addr, str_data, str_readable);
    }

    if (length > 0)
    {
        sprintf(str_addr, "%-16lx", (unsigned long)(void *)cur_pos);
        for (i = 0; i < length; i++)
        {
            sprintf(str_data + i*3, "%02hhx ", cur_pos[i]);
            if (cur_pos[i] > 31 &&  cur_pos[i] < 127)
            sprintf(str_readable + i, "%c", (char)(cur_pos[i]));
            else
            sprintf(str_readable + i, "%c", '*');
        }
        for (i = length; i < 16; i++)
        {
            sprintf(str_data + i*3, "%s", "   ");
            sprintf(str_readable + i, "%c", ' ');
        }
        PrintText("%s: %s: %s\r\n", str_addr, str_data, str_readable);
    }


}

#endif
