#include "config.h"

/**Porgress */
bool database_connection = true;
bool client_connection = false;
bool crawling = false;
bool report = false;

static std::time_t t = std::time(nullptr);

bool sockServerStop = false;

/**Server info */
int total_count = 0;
std::tm begin_time = *std::localtime(&t);
int failure_count = 0;

/**Workload */
std::string clientA_name = "A";
std::string clientB_name = "B";
std::string clientC_name = "C";
int total_A = 100000;
int total_B = 100000;
int total_C = 100000;

/**Website info */
int yahoo_cnt = 0;
int yahoo_fail = 0;
std::tm yahoo_begin = *std::localtime(&t);;

int ptt_cnt = 0;
int ptt_fail = 0;
std::tm ptt_begin = *std::localtime(&t);;

int ettoday_cnt = 0;
int ettoday_fail = 0;
std::tm ettoday_begin = *std::localtime(&t);;

/**Client info
 * state=0, off
 *      =1, run
 *      =2, suspend
 */
int clientState[3] = {0};
int clientCrawl[3] = {0};
int clientFail[3] = {0};
std::tm clientBegin[3] = {*std::localtime(&t)};

/*int clientB_state = 0; //suspend
int clientB_crawl = 0;
int clientB_fail = 0;
std::tm clientB_begin = *std::localtime(&t);;

int clientC_state = 0;
int clientC_crawl = 0;
int clientC_fail = 0;
std::tm clientC_begin = *std::localtime(&t);;*/
