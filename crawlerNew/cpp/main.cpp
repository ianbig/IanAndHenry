#include "crawler.h"

int main(int argc, char **argv) {

    if( argc == 2) {
        int news_type = -1;
        crawler master;

        if(argv[1] == "storm") {
            news_type = 0;
        }

        else if(argv[1] == "head") {
            news_type = 1;
        }

        else if(argv[1] == "ettoday") {
            news_type = 2;
        }

        master.start(news_type);
    }
    
    else {
        std::cout << "USAGE: ./crawel [news website]" << std::endl;
    }

    return 0;
}