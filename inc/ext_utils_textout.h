/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef __EXT_UTILS_TEXTOUT_H_
#define __EXT_UTILS_TEXTOUT_H_

#include <windows.h>
#include <tchar.h> 
#include <windowsx.h>

void text_out_full(HDC hdc, int x, int y, int size
    ,COLORREF bg, COLORREF fg, TCHAR *text, int len);

void text_out_test(HDC hdc);

#endif

