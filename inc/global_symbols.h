/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */


#ifndef __GLOBAL_SYMBOLS_H_
#define __GLOBAL_SYMBOLS_H_

#include <windows.h>
#include "defs.h"



extern HINSTANCE g_hInstance;
extern int init_over;

int register_frame();
void set_frame_title(TCHAR *file_name);

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT message,WPARAM wParam, LPARAM lParam);

extern HWND    hwnd_frame;
extern HWND hwndTip;
extern int  doc_modified;
void save_doc_file(TCHAR *file_name);
void load_doc_file(TCHAR *file_name);


extern HWND    hwnd_toolbar;
extern int     toolbar_height;

extern HWND    hwnd_statusbar;
extern int     statusbar_height;


int CreateToolbar();
int CreateStatusBar();
int create_windows(int iCmdShow);

void resize_window(HWND hwnd);

#endif

