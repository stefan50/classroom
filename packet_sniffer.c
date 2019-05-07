#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */
#include <netinet/in.h>
#include <arpa/inet.h>

void* listen_traffic() {
    //thread for listening
    int socket_id = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    close(socket_id);
    //pthread_exit(NULL);
}

int main() {
    struct pthread_t* threads = (struct pthread_t*)malloc(2);
    

    //pthread_create(threads, NULL, listen_traffic, NULL);

    int socket_id = socket(AF_INET, SOCK_RAW, IPPROTO_TCP); 
    while(1) {
        unsigned char* buffer = (unsigned char*)malloc(655366);
        printf("message = %d\n", recv(socket_id, buffer, sizeof buffer, MSG_TRUNC));
        struct iphdr* iph = (struct iphdr*) buffer;
        struct sockaddr_in* source = (struct sockaddr_in*)malloc(65536);
        memset(source, 0, sizeof(&source));
        source->sin_addr.s_addr = iph->saddr;
        printf("Source IP: %s\n", inet_ntoa(source->sin_addr));
        struct tcphdr* tcph = (struct tcphdr*)(buffer + iph->ihl*4);

        printf("Source port = %d\n", ntohs(tcph->source));
        printf("Destination port = %d\n", ntohs(tcph->dest));
        free(buffer);
    }
    //pthread_join(threads, NULL);
    
    free(threads);
    close(socket_id);
    return 0;
}
