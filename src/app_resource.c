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
#include "global_symbols.h"
#include "ext_utils_textout.h"

HFONT h_font_32_px, h_font_resolve;
void create_app_fonts()
{
    h_font_32_px = create_font(32, NULL);
    h_font_resolve = create_font(40, "Courier New");
}

HBITMAP  h_img_on_line, h_img_off_line, h_img_do_job, h_img_job_finished;
void app_resource_init()
{
    create_app_fonts();

    h_img_on_line  = (HBITMAP)LoadImage(g_hInstance,
                          TEXT("icon_on_line"),
                          IMAGE_BITMAP, 32, 32,
                          LR_DEFAULTCOLOR);
    h_img_off_line = (HBITMAP)LoadImage(g_hInstance,
                          TEXT("icon_off_line"),
                          IMAGE_BITMAP, 32, 32,
                          LR_DEFAULTCOLOR);

    h_img_do_job = (HBITMAP)LoadImage(g_hInstance,
                          TEXT("icon_do_job"),
                          IMAGE_BITMAP, 32, 32,
                          LR_DEFAULTCOLOR);

    h_img_job_finished = (HBITMAP)LoadImage(g_hInstance,
                          TEXT("icon_job_finished"),
                          IMAGE_BITMAP, 32, 32,
                          LR_DEFAULTCOLOR);


}

