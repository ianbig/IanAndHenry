#include "crawler.h"

int main(int argc, char **argv) {

    if( argc == 2) {
        int news_type = -1;
        crawler master;

        if(strcmp( argv[1], "storm") == 0) {
            news_type = 0;
        }

        else if(strcmp( argv[1], "cts") == 0) {
            news_type = 1;
        }

        else if(strcmp( argv[1], "ettoday") == 0) {
            news_type = 2;
        }
        if(news_type == -1) {
            std::cout << "ERROR: NOT designated website" << std::endl;
            exit(-1);
        }
        master.start(news_type);
    }
    
    else {
        std::cout << "USAGE: ./crawel [news website]" << std::endl;
    }

    return 0;
}