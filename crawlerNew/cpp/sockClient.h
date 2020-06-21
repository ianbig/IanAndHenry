#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// c++ : because the header files between c and cpp are different
#include <iostream>
#include <arpa/inet.h>
#include <sys/uio.h>

class sockClient
{
private:
    int MAX_MSG;
    int clientfd;
    int connect_state;
    struct sockaddr_in client_info;
    bool runnable;
    char recvbuf[512];
    char sendbuf[512];
    void _check();
public:
    sockClient();
    ~sockClient();
    void check();
    void send_message(int, int, std::string);
    void run();
};

