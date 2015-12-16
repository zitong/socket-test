//
//  main.cpp
//  Server
//
//  Created by lichenyang on 15/12/15.
//  Copyright © 2015年 lichenyang. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <sys/socket.h>
#include <sys/netport.h>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
        socklen_t addr_length;
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addr_length);
        
        char readBuffer[2048];
        ssize_t ln = recv(clientSocket, readBuffer, 1024, MSG_WAITALL);
        printf("%s, %d\n",readBuffer, (int)ln);
        close(clientSocket);
    }
    return 0;
}
