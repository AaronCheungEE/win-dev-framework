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
#include <tchar.h> 
#include <commctrl.h>
#include <windowsx.h>

#include "ext_utils_textout.h"

void text_out_full(HDC hdc, int x, int y, int size
    ,COLORREF bg, COLORREF fg, TCHAR *text, int len)
{
    SetBkColor (hdc, bg) ;
    SetTextColor(hdc, fg) ;
    TextOut(hdc, x, y, text, len) ; 
}

void text_out_test(HDC hdc)
{
    text_out_full(hdc, 200, 200, 30
    ,RGB(0x00,0x00,0x00), RGB(0xFF,0xFF,0xFF), TEXT("hello"), 5);
}

