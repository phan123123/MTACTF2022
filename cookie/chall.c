#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 200
#define PORT 1337
#define SA struct sockaddr

char name[MAX];
   
void getdata(int connfd)
{
    char buff[MAX];
    memset(buff, 0, MAX);
    memset(name, 0, MAX);
    char wel[20] = "Send your resport:\n\x00";
    char wel2[20] = "Give me your name:\n\x00";
    write(connfd,wel2,sizeof(wel2)); 
    read(connfd,name,200-1);
    write(connfd,wel,sizeof(wel)); 
    read(connfd,buff,0x200-1);
}

void pwn(char *cmd){
    system(cmd);
}
   
int main()
{
    int sockfd, connfd, len, pid;
    struct sockaddr_in servaddr, cli;
    char msg[40] = "\nThank you for report!!\n\x00";
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    
    while(1){
        connfd = accept(sockfd, (SA*)&cli, &len);
        if (connfd < 0) {
            printf("server accept failed...\n");
            continue;
        }
        else
            printf("server accept the client %d...\n",connfd);
        if ((pid = fork()) == -1){
            printf("Error fork\n");
            close(connfd);
        }
        else if(pid == 0){
            close(sockfd);
            getdata(connfd);
            write(connfd, msg, sizeof(msg));
            exit(0);
        }
        close(connfd);
    }
    close(sockfd);
}
