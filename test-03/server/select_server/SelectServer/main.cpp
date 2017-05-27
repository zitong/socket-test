#include <iostream>
#include <sys/socket.h>
#include <sys/netport.h>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>
#include <vector>
#include <fcntl.h>



int main(int argc, char * argv[]) {

    signal(SIGPIPE, SIG_IGN);
    int set = 1;
    //create socket handle
    int serverSock = socket(PF_INET, SOCK_STREAM, 0);
    setsockopt(serverSock, SOL_SOCKET, SO_NOSIGPIPE, (void *)&set, sizeof(int));
    if(serverSock < 0){
        printf("create socket fail!\n");
    }
    //bind ip and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9005);
    bzero(&(addr.sin_zero), 0);
    int ret = bind(serverSock, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0){
        printf("bind port fail!\n");
    }
    //listen
    listen(serverSock, 5);

    timeval time;
    time.tv_sec = 2;
    time.tv_usec = 500;
    std::vector<int> clientArr;
    clientArr.push_back(serverSock);
    char buff[1024];
    const char *sendBuff = "hello clinet!\n";
    int socketNum = serverSock+1;

    while (true){
        fd_set read_fds;
        fd_set exception_fds;
        FD_ZERO(&read_fds);
        FD_ZERO(&exception_fds);

        for(std::vector<int>::iterator iter = clientArr.begin(); iter != clientArr.end(); iter++)
        {
            FD_SET(*iter, &read_fds);
        }
        int status = select(socketNum, &read_fds, NULL, &exception_fds, NULL);

        if(status < 0){
            printf("select error \n");
        }
        int clientSocket = 0;
        bool isFlushServer = false;
        for(std::vector<int>::iterator iter = clientArr.begin(); iter != clientArr.end(); )
        {
            if(FD_ISSET(serverSock, &read_fds) && isFlushServer == false){
                struct sockaddr_in client_addr;
                socklen_t clientSize = sizeof(client_addr);
                clientSocket = accept(serverSock, (struct sockaddr*)&client_addr, &clientSize);
                int flags = fcntl(clientSocket, F_GETFL, 0);
                fcntl(clientSocket, F_SETFL, flags | O_NONBLOCK);
                FD_SET(clientSocket, &read_fds);
                clientArr.push_back(clientSocket);
                socketNum = clientSocket +1;
                isFlushServer = true;
                break;
            }else if(FD_ISSET(*iter, &read_fds)){
                printf("have a read socket!");
                long int result = -1;
                int stau = ioctl(*iter, FIONREAD, &result);
                if(stau){
                    printf("Socket::nextReadSize: error ioctl ");
                }
                printf("result:%d   :", result);
                if(int(result) == 0){
                    printf("socket disconnect!!!\n");
                    clientArr.erase(iter);
                    close(*iter);
                } else{
                    memset(buff, 0, 1024);
                    read(*iter, buff, 1024);
                    printf("%s", buff);

                    size_t lenght = strlen(sendBuff);
                    int sedret = send(*iter, sendBuff, lenght, NULL);
                    if(sedret <0){
                        printf("send error !code:%s", sedret);
                    }
                    iter++;
                }
            } else{
                iter++;
            }
        }
    }
    return 0;
}