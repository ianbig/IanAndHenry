/* 
History:
    Written by Ian Liu 5/2020
*/


#include "crawler.h"

crawler::~crawler() {
    char *tmp;
    for(int i = 0; i < commitQueue.size(); i++) {
        tmp = commitQueue.at(i);
        delete [] tmp;
    }
}

// start craweling webpage specified in seed.log
int crawler::start(int news_type) {
    char *tmp_url;
    size_t real_record_size = 0;
    FILE *fstream = NULL;
    char *line = NULL;
    char *copy_line = NULL;
    size_t get_line_size = 0;
    bool record_size_not_exceed = true;
    clock_t start, end;
    int parser_check;
    std::string seed_file, uncomit_file, record_file;


    if(news_type == 0) {
        seed_file = "./DB/storm_seed.log";
        uncomit_file = "./DB/storm_uncommit.log";
        record_file = "./DB/storm.rec";
    }

    else if(news_type == 1) {
        seed_file = "./DB/head_seed.log";
        uncomit_file = "./DB/head_uncommit.log";
        record_file = "./DB/head.rec";
    }

    else if(news_type == 2) {
        seed_file = "./DB/ettoday_seed.log";
        uncomit_file = "./DB/ettoday_uncommit.log";
        record_file = "./DB/ettoday.rec";
    }

    std::cout << "=========start craweling==========" << std::endl;

    
    while(real_record_size < MAX_RECORD) {
        // the reason for the use of outer loop is to automatically refresh queue in parser
        Parser parser;
        int file_check = 0;
        size_t line_size = 0;
        size_t record_size = 0;
        size_t master_parser_size = 0;

        fstream = fopen(seed_file.c_str(), "r+");
        if(!fstream) {
            std::cerr << "ERROR: " << seed_file << " not exist" << std::endl;
            return ERROR_DOCUMENT_NOT_EXISTS;
        }
        
        while ((file_check = getline(&line, &get_line_size, fstream) ) != -1) {
            line_size = strlen(line);
            copy_line = new char[line_size + 1];
            copy_line[line_size] = 0;
            memmove(copy_line, line, line_size); 
            commitQueue.push_back(copy_line);
            free(line);
            line = NULL;
        } //load data in seed.log
        if(line != NULL ) {
            free(line);
            line = NULL;
        } // last call of getline would malloc memory again
        
        fclose(fstream);

        if(!record_size_not_exceed) 
        // this if statement prevent the first loop of start step into loading uncommit.log
        // since we do not usually load thing from uncommit.log at first loop
        // we expect uncommit.log is empty
        {
            fstream = fopen(uncomit_file.c_str(), "r+");

            if(!fstream) {
                std::cerr << "ERROR: " << uncomit_file << " not exists" << std::endl;
                return ERROR_DOCUMENT_NOT_EXISTS;
            }

            while ((file_check = getline(&line, &get_line_size, fstream) ) != -1) {
                line_size = strlen(line);
                copy_line = new char[line_size + 1];
                copy_line[line_size] = 0;
                memmove(copy_line, line, line_size);
                commitQueue.push_back(copy_line);
                free(line);
                line = NULL;
            } //load url in uncommit.log
            fclose(fstream);
        }

        if(line != NULL ) {
            free(line);
            line = NULL;
        } // last call of getline would malloc memory again
        
        if(commitQueue.empty()) {
            std::cerr << "ERROR: " << seed_file << " is empty" << std::endl;
            return  ERROR_SEED_EMPTY;
        }
        
        while(! commitQueue.empty() &&  ( record_size_not_exceed = (record_size <= MAX_RECORD_SIZE && master_parser_size <= MAX_URL_CAPACITY) ) ){
            
            tmp_url = commitQueue.front();
            tmp_url = strtok(tmp_url,"\n");
            if(tmp_url == NULL) {
                delete [] tmp_url;
                commitQueue.erase(commitQueue.begin());
                continue;
            }
            std::cout << tmp_url << std::endl;

            // flow control
            start = clock();
            end = clock();
            while (  ( (double)(end - start) / CLOCKS_PER_SEC ) < 0.5 ) {
                end = clock();
            }
            start = clock();

            parser_check = parser.fetch(tmp_url, news_type);
            delete [] tmp_url;
            commitQueue.erase(commitQueue.begin());
            record_size = parser.get_record_queue_size();
            master_parser_size = parser.get_master_parser_size();
        }
        
        real_record_size += parser.get_record_amount();
        std::cerr << "Record Size: " << real_record_size << std::endl;
        if(record_size_not_exceed == false ) write_out_commit_queue(uncomit_file); // if record_size_not exceed is set to false either queue between filter and seed.log is exceed or queue between parser and ettoday.rec is excced size
        if(record_size_not_exceed == true ) std::cout << "Commit Queue is empty" << std::endl;
        parser.write_out_url(seed_file);
        parser.write_out_record(record_file);
        

    }
    std::cout << "====== craweling finish =====" << std::endl;
    std::cout << "Current Stored Record: " << real_record_size << std::endl;
    return 0;
}



void crawler::write_out_commit_queue(std::string filePath) {
    std::cerr << "Write out to uncommit Queue" << std::endl;
    std::ofstream fout;
    char *tmp;
    fout.open(filePath, std::ios::out);

    for(int i = 0; i < commitQueue.size(); i++) {
        tmp = commitQueue.front();
        tmp = strtok(tmp,"\n");
        if(tmp) fout << tmp << std::endl;
        delete [] tmp;
        commitQueue.erase(commitQueue.begin());
    }

    fout.close();
}