#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

uint8_t broadcastMessage( )
{
    int sockfd;
    char buffer[1024];
    char *msg = "hello broadcast!";
    struct sockaddr_in servaddr;

    if( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("error");
        exit(0);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);
    servaddr.sin_addr.s_addr = inet_addr("192.168.0.255");

    while(1){
    int n;
    sendto(sockfd, (const char *)msg, strlen(msg), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

    printf("Hello message sent!");
    n = recvfrom(sockfd, (char *)buffer, 1024, 0, (struct sockaddr *) &servaddr, NULL);

    buffer[n] = '\0';
    printf("Server: %s\n",buffer);
    }
    close(sockfd);
    return 0;
}
