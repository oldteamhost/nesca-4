/*
 * NESCA4
 * by oldteam & lomaster
 * license GPL-3.0
 * - Сделано от души 2023.
*/

#include <iostream>
#include <poll.h>
#include <stdint.h>
#include <signal.h>
#include <chrono>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <mutex>
#include <unistd.h>
#include "include/icmpproto.h"
#include "include/socket.h"
#include "include/headers.h"

int 
send_icmp_packet(struct sockaddr_in* addr, int type,
				int code, int ident, int seq, int ttl){
	int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (fd == EOF){return -1;}
	if (setsockopt(fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0){close(fd);return -1;}

	struct icmp4_header icmp;
	memset(&icmp, 0, sizeof(icmp));
	fill_icmp_header(&icmp, type, code, 0, ident, seq);
	strncpy(icmp.magic, MAGIC, MAGIC_LEN);
	icmp.checksum = htons(checksum_16bit_icmp((unsigned char*)&icmp, sizeof(icmp)));

	const int bytes = sendto(fd, &icmp, sizeof(icmp), 0,(struct sockaddr*)addr, sizeof(*addr));
    if (bytes == EOF) {
		close(fd);
        return -1;
    }
	close(fd);
	return 0;
}

int 
recv_icmp_packet(const char* dest_ip, int timeout_ms, int type,
				int code, int identm){

	int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (fd == EOF){return -1;}

    char buffer[1500];
    struct sockaddr_in peer_addr;
	memset(&peer_addr, 0, sizeof(peer_addr));

	/*Установка таймаута на сокет*/
	int result = set_socket_timeout(fd, timeout_ms, 1, 1);
	if (result < 0) {
    	return -1;
	}

    int addr_len = sizeof(peer_addr);
    auto start_time = std::chrono::steady_clock::now();
	for (;;){
    	int bytes = recvfrom(fd, buffer, sizeof(buffer), 0,(struct sockaddr*)&peer_addr, (socklen_t *)&addr_len);
		if (bytes == EOF) {
			/*Сработал таймаут.*/
			if (errno == EAGAIN || errno == EWOULDBLOCK){
				close(fd);
				return -1;
			}
			/*Просто ошибка.*/
			close(fd);
        	return -1;
    	}
		/*Получение IP заголовка.*/
		struct ip_header *iph = (struct ip_header*)buffer;

		/*Поулучение из него IP отправителя.*/
	   	struct sockaddr_in source;
	   	memset(&source, 0, sizeof(source));
	   	source.sin_addr.s_addr = iph->saddr;
		struct in_addr dest; dest.s_addr = inet_addr(dest_ip);

		if (source.sin_addr.s_addr != dest.s_addr){
		  	auto current_time = std::chrono::steady_clock::now();
		  	auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
		  	if (elapsed_time >= timeout_ms) {
			 	close(fd);
			 	return -1;
		  	}
			continue;
		}
		else {
			struct icmp4_header* icmp = (struct icmp4_header*)(buffer + 20);
			if (type == ICMP_ECHO){
				if (icmp->type == ICMP_ECHOREPLY){
					close(fd);
					return 0;
				}
			}
			if (type == ICMP_TIMESTAMP){
				if (icmp->type == ICMP_TIMESTAMPREPLY){
					close(fd);
					return 0;
				}
			}
			if (type == ICMP_INFO_REQUEST){
				if (icmp->type == ICMP_INFO_REPLY){
					close(fd);
					return 0;
				}
			}
		}
		break;
	}

	close(fd);
	return -1;
}
