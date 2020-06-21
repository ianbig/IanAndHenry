#include "sockClient.h"
sockClient::sockClient()
{
    MAX_MSG = 512;

    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1)
        perror("socket");

    bzero(&client_info, sizeof(client_info));
    client_info.sin_family = PF_INET;
    client_info.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_info.sin_port = htons(8080);

    connect_state = connect(clientfd, (struct sockaddr *)&client_info, sizeof(client_info));
    if (connect_state == -1)
        perror("connect");
}

sockClient::~sockClient()
{
}

void sockClient::check() {
    runnable = true;
    if (clientfd == -1) {
        std::cerr << "X creating socketfd failed" << std::endl;
        runnable = false;
    }
    else
        std::cerr << "V creating socketfd succeed" << std::endl;

    if (connect_state == -1) {
        std::cerr << "X fail to connect to server" << std::endl;
        runnable = false;
    }
    else
        std::cerr << "V connect to server successfully" << std::endl;
    
    
}

void sockClient::_check() {
    if (clientfd == -1 || connect_state == -1) {
        runnable = false;
    }
    else
        runnable = true;
}


void sockClient::send_message(int status, int news_type, std::string url) {
	if (runnable) {
		std::string str = std::to_string(status) + " " + std::to_string(news_type) +  " " + url;
		if (write(clientfd, str.c_str(), sizeof(str)) < 0)
			std::cerr << "cannot send" << std::endl;
	}
	else
		std::cerr << "please use check() before sending messages" << std::endl;
}

void sockClient::run() {
    _check();
    int nbytes;
    if (!runnable){
        std::cerr << "Please check where goes wrong" << std::endl;
        return;
    }
    recv(clientfd, recvbuf, sizeof(recvbuf), 0);
    std::cout << recvbuf << std::endl;
    while(1) {
        std::cout << "> ";
        std::cin.getline(sendbuf, sizeof(sendbuf));
        if (strncmp(sendbuf, "quit", 4)==0)
            break;
        send(clientfd, sendbuf, sizeof(sendbuf), 0);
    }
}
