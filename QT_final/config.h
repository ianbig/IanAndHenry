#ifndef CONFIG_H
#define CONFIG_H

#include <ctime>
#include <string>

extern bool sockServerStop;

/**Porgress */
extern bool database_connection;
extern bool client_connection;
extern bool crawling;
extern bool report;

/**Server info */
extern int total_count;
extern std::tm begin_time;
extern int failure_count;

/**Workload */
extern std::string clientA_name;
extern int total_A;
extern std::string clientB_name;
extern int total_B;
extern std::string clientC_name;
extern int total_C;

/**Website info */
extern int yahoo_cnt;
extern int yahoo_fail;
extern std::tm yahoo_begin;

extern int ptt_cnt;
extern int ptt_fail;
extern std::tm ptt_begin;

extern int ettoday_cnt;
extern int ettoday_fail;
extern std::tm ettoday_begin;

/**Client info */
extern int clientState[3];
extern int clientCrawl[3];
extern int clientFail[3];
extern std::tm clientBegin[3];

/*extern int clientB_state;
extern int clientB_crawl;
extern int clientB_fail;
extern std::tm clientB_begin;

extern int clientC_state;
extern int clientC_crawl;
extern int clientC_fail;
extern std::tm clientC_begin;*/

#endif // CONFIG_H
