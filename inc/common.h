/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef __COMMON_H_
#define __COMMON_H_

#include <windows.h>
#include <tchar.h> 
#include <commctrl.h>
#include <windowsx.h>
#include <stdint.h>
#include <stdio.h>

#include "defs.h"
#include "app_property.h"

#define    ARRAY_SIZE(array_name)    (sizeof(array_name)/sizeof(array_name[0]))

void add_tip(HWND htip_control, HWND hwnd, TCHAR *tips);

static inline HANDLE launch_thread(LPTHREAD_START_ROUTINE ThreadFunc, LPVOID lpParameter)
{
    HANDLE hThrd;
    DWORD threadId;
    
    hThrd = CreateThread(NULL,
        0,
        ThreadFunc,
        lpParameter,
        0,
        &threadId );
    return hThrd;

}

#endif

