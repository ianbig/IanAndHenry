#ifndef SOCKSERVER_H
#define SOCKSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// c++ : because the header files between c and cpp are different
#include <iostream>
#include  <arpa/inet.h>
#include <sys/uio.h>
#include <atomic>

#include <map>

class sockServer
{
private:
    std::map<int, int> m;
    int MAX_CLIENT, MAX_MSG;
    int client_socket[30];
    int serverfd, clientfd;
    int bind_state, listen_state;
    int on;
    struct sockaddr_in server_info, client_info;
    socklen_t client_size;
    fd_set active_set, read_set;
    int read_from_client(int);
    void _check();
public:
    sockServer();
    ~sockServer();
    void check();
    void update();
    void run();
    bool renewfd();
    bool runnable;
};

#endif
