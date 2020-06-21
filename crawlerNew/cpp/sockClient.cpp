#include "sockClient.h"

ssize_t send_all(int fd, void const* buf, size_t buf_len) {
    for(size_t len = buf_len; len;) {
        ssize_t r = ::send(fd, buf, len, 0);
        if(r <= 0)
            return r;
        buf = static_cast<char const*>(buf) + r;
        len -= r;
    }
    return buf_len;
}

void send_string(int fd, std::string const& msg) {
    ssize_t r;
    // Send message length.
    uint32_t len = msg.size();
    len = htonl(len); // In network byte order.
    if((r = send_all(fd, &len, sizeof len)) < 0)
        throw std::runtime_error("send_all 1");
    // Send the message.
    if((r = send_all(fd, msg.data(), msg.size())) < 0)
        throw std::runtime_error("send_all 2");
}

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
        send_string(clientfd, str);
		/*if (write(clientfd, str.c_str(), sizeof(str)) < 0)
			std::cerr << "cannot send" << std::endl;*/
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
