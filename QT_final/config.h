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
extern int wind_cnt;
extern int wind_fail;
extern std::tm wind_begin;

extern int ebc_cnt;
extern int ebc_fail;
extern std::tm ebc_begin;

extern int ettoday_cnt;
extern int ettoday_fail;
extern std::tm ettoday_begin;

/**Client info */
extern int clientState[3];
extern int clientCrawl[3];
extern int clientFail[3];
extern std::tm clientBegin[3];
extern std::string clientUrl[3];


#endif // CONFIG_H
