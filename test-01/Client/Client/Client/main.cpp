//
//  main.cpp
//  Client
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
int main(int argc, const char * argv[]) {
    
    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        printf("create socket faild!");
        return -1;
    }
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9999);
    bzero(&(addr.sin_zero), 0);
    
    int cRet = connect(clientSocket, (const struct sockaddr *)&addr, sizeof(addr));
    if (cRet < 0) {
        printf("connect socket faild!");
        return -1;
    }
    const char * sendBuffer = "Hello world!!!";
    ssize_t sRet = send(clientSocket, sendBuffer, strlen(sendBuffer), 0);
    if (sRet < 0){
        printf("send socket faild!");
        return -1;
    }
    close(clientSocket);
    return 0;
}
