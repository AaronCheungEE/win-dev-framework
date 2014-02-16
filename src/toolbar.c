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
#include "global_symbols.h"
#include "res.h"

HWND    hwnd_toolbar;
int     toolbar_height;

TBBUTTON at_button[] =                
    {
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {0, IDT_TOOLBAR_BUTTON1, TBSTATE_ENABLED, TBSTYLE_AUTOSIZE , {0}, 0, "���ǰ�Ŧ1"},
        {1, IDT_TOOLBAR_BUTTON2, TBSTATE_ENABLED, TBSTYLE_AUTOSIZE , {0}, 0, "���ǰ�Ŧ2"},
        {I_IMAGENONE , -1, TBSTATE_ENABLED, TBSTYLE_SEP|TBSTYLE_AUTOSIZE},
        {2, IDT_TOOLBAR_BUTTON3, TBSTATE_ENABLED, TBSTYLE_AUTOSIZE , {0}, 0, "���ǰ�Ŧ3" },
    };

HBITMAP hbmpToolbar[3];
HIMAGELIST g_hImageList;

WNDPROC old_tb_proc;
LRESULT CALLBACK my_tb_proc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 	int cxClient, cyClient;
    RECT  rc;
    int button_width, button_height;
 	switch (message)
 	{
     	case WM_SIZE :
            cxClient = LOWORD (lParam) ;
      		cyClient = HIWORD (lParam) ;

            /* �������ؼ���С��λ�õ��� */
            /* �Ȼ�ȡ���ұߵİ�Ŧ�����굽rc�С�
               Ȼ����ݴ�����������ؼ���λ�� */
            SendMessage(hwnd_toolbar,TB_GETITEMRECT,(WPARAM)ARRAY_SIZE(at_button)-1,(LPARAM)&rc);
            button_width = rc.right-rc.left;
            button_height = rc.bottom-rc.top;

            break;


        case 	WM_COMMAND:
            /* �������ϵĿؼ���Ϣ���� */
            break;

 	}

    return CallWindowProc (old_tb_proc, hwnd, message, wParam,lParam) ;
}

int CreateToolbar()
{

BITMAP BMPInfo;
HIMAGELIST h0, h1;
HICON hiconItem; 

//����������
    hwnd_toolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL
    , WS_CHILD | WS_VISIBLE | WS_BORDER |  TBSTYLE_TOOLTIPS | TBSTYLE_LIST  
    , 0, 0, 0, 0,
        hwnd_frame, (HMENU)NULL, g_hInstance, NULL);
    SendMessage(hwnd_toolbar, TB_SETEXTENDEDSTYLE, 0,  TBSTYLE_EX_MIXEDBUTTONS );

    if(hwnd_toolbar == NULL)
    {
        err_info_box(NULL, TEXT ("CreateToolbar failed!")) ;
        return FAIL;
     }
    
//���ذ�Ŧͼ��
    h0 = ImageList_Create(32,32,ILC_MASK|ILC_COLORDDB,4,0);

    hiconItem = LoadIcon(g_hInstance, TEXT("icon_1"));
    ImageList_AddIcon(h0, hiconItem);
    DestroyIcon(hiconItem);
    
    hiconItem = LoadIcon(g_hInstance, TEXT("icon_2"));
    ImageList_AddIcon(h0, hiconItem);
    DestroyIcon(hiconItem);
    

    hiconItem = LoadIcon(g_hInstance, TEXT("icon_3"));
    ImageList_AddIcon(h0, hiconItem);
    DestroyIcon(hiconItem);

    //���ù�������Ŧ����״̬��ͼ��
    SendMessage(hwnd_toolbar,TB_SETIMAGELIST,0,(LPARAM)h0);

    h1 = ImageList_Create(32,32,ILC_COLORDDB,4,0);

    hiconItem = LoadIcon(g_hInstance, TEXT("icon_1"));
    ImageList_AddIcon(h1, hiconItem);
    DestroyIcon(hiconItem);
    
    hiconItem = LoadIcon(g_hInstance, TEXT("icon_2"));
    ImageList_AddIcon(h1, hiconItem);
    DestroyIcon(hiconItem);
    

    hiconItem = LoadIcon(g_hInstance, TEXT("icon_3_dis"));
    ImageList_AddIcon(h1, hiconItem);
    DestroyIcon(hiconItem);

    //���ù�������Ŧ������״̬��ͼ��
    SendMessage(hwnd_toolbar,TB_SETDISABLEDIMAGELIST,0,(LPARAM)h1);

    //����ť�빤��������
    SendMessage(hwnd_toolbar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
    SendMessage(hwnd_toolbar, TB_ADDBUTTONS, ARRAY_SIZE(at_button), (LPARAM)at_button);
    SendMessage(hwnd_toolbar,TB_SETMAXTEXTROWS, 0, 0);
    
    // Resize the toolbar, and then show it.
    SendMessage(hwnd_toolbar, TB_AUTOSIZE, 0, 0); 
    ShowWindow(hwnd_toolbar,  TRUE);
    toolbar_height = win_height(hwnd_toolbar);

    

    {
        /* �ڹ������ϴ�������Ŀؼ�����������checkbox��... */

        /* �����������໯���Ա��ڴ���ؼ���Ϣ */
        old_tb_proc = (WNDPROC) SetWindowLong (hwnd_toolbar, 
                                     	GWL_WNDPROC, (LONG) my_tb_proc) ;
    }

    add_tip(hwndTip, hwnd_toolbar, TEXT("hello, I am the toolbar."));
    return SUCCESS;
}



