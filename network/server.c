#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF 2048


int main(int argc, char *argv[]){
    char buffer[BUF];
    struct sockaddr_in server_addr,client_addr;
    char temp[20];

    int server_fd,client_fd;

    int len,msg_size;



}
