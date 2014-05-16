/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __SOCKET_H__
#define  __SOCKET_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <winsock2.h>

int win_socket_init();
int udp_socket_init(const char *ipstr, uint16_t port);
int tcp_socket_init(const char *ipstr, uint16_t port);
int fd_readable(int fd, int usec);
int udp_socket_recvfrom(int sockfd, void *buf, int buf_size, struct sockaddr_in *peer_addr);
int udp_socket_sendto(int sockfd, void *buf, int buf_size, struct sockaddr_in *peer_addr);
void make_sockaddr(struct sockaddr_in *sock_addr, uint32_t ip, uint16_t port);
int sockaddr_equal(struct sockaddr_in *sock_addr1, struct sockaddr_in *sock_addr2);
char * get_ipstr(struct sockaddr_in *sock_addr, char *ip);
uint16_t get_port(struct sockaddr_in *sock_addr, uint16_t *port);

#endif


