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
#include "common.h"
#include "utils.h"
#include "global_symbols.h"

HWND    hwnd_statusbar;
int     statusbar_height;

TCHAR *fields_name[]  = {TEXT("�ֶ�A"), TEXT("�ֶ�B"), TEXT("�ֶ�C"), TEXT("�ֶ�D")};
int    fields_width[] = {200, 400, 700, -1};
int    fields_value[] = {3, 7, 2, 1};

void update_statusbar()
{
    TCHAR info[32];
    
    _stprintf (	info, TEXT("%s:  %d"), fields_name[0], fields_value[0]) ;
    SendMessage(hwnd_statusbar, SB_SETTEXT,0, (LPARAM)info); 

    _stprintf (	info, TEXT("%s:  %d"), fields_name[1], fields_value[1]) ;
    SendMessage(hwnd_statusbar, SB_SETTEXT,1, (LPARAM)info); 

    _stprintf (	info, TEXT("%s:  %d"), fields_name[2], fields_value[2]) ;
    SendMessage(hwnd_statusbar, SB_SETTEXT,2, (LPARAM)info); 

    _stprintf (	info, TEXT("%s:  %d"), fields_name[3], fields_value[3]) ;
    SendMessage(hwnd_statusbar, SB_SETTEXT,3, (LPARAM)info); 

}

int CreateStatusBar()
{
    hwnd_statusbar = CreateWindow(STATUSCLASSNAME, NULL,
        SBARS_SIZEGRIP | WS_CHILD | WS_VISIBLE|WS_BORDER,0,0,0,0, hwnd_frame, NULL, g_hInstance, NULL);
    ShowWindow(hwnd_statusbar,  TRUE);
    statusbar_height = win_height(hwnd_statusbar);
    SendMessage(hwnd_statusbar, SB_SETPARTS, (WPARAM)ARRAY_SIZE(fields_width), (LPARAM)fields_width);
    update_statusbar();
    add_tip(hwndTip, hwnd_statusbar, TEXT("hello. ����״̬��"));

}


