/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef __EXT_UTILS_AV_H_
#define __EXT_UTILS_AV_H_

#include <windows.h>
#include <tchar.h> 
#include <windowsx.h>

#ifdef _USE_AV
void av_test(void);
#else
#define av_test()  do { ; } while (0)
#endif

#endif

