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

HFONT h_font_32_px, h_font_resolve;
void create_app_fonts()
{
    h_font_32_px = create_font(32, NULL);
    h_font_resolve = create_font(40, "Courier New");
}


void app_resource_init()
{
    create_app_fonts();
}

