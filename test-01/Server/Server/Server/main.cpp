//
//  main.cpp
//  Server
//
//  Created by lichenyang on 15/12/15.
//  Copyright © 2015年 lichenyang. All rights reserved.
//

#include <iostream>
#include <sys/socket.h>
#include <sys/netport.h>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

int main(int argc, const char * argv[]) {
	
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        printf("create socket faild!\n");
        return -1;
    }
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9999);
    bzero(&(addr.sin_zero), 0);
    
    int bRet = bind(serverSocket, (const struct sockaddr *)&addr, sizeof(addr));
    if (bRet < 0) {
        printf("bind faild!\n");
    }
    
    listen(serverSocket, 20);
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t addr_length = sizeof(struct sockaddr_in);  ;
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addr_length);
        sleep(1);
        char *clientIp = inet_ntoa(clientAddr.sin_addr);
        printf("client:(%s) connect\n",clientIp);
        const char * sendBuffer = "Hello world!!!";
        send(clientSocket, sendBuffer, strlen(sendBuffer), 0);
        long result;
        ioctl(clientSocket, FIONREAD, &result);
        printf("socket buffer size: %ld\n",result);
        char readBuffer[1024];
        ssize_t ln = recv(clientSocket, readBuffer, 1024, MSG_WAITALL);
        printf("%s, %d\n",readBuffer, (int)ln);
        close(clientSocket);
    }
    return 0;
}
