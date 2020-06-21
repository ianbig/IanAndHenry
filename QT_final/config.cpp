#include "config.h"
#include <atomic>

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
int wind_cnt;
int wind_fail = 0;
std::tm wind_begin = *std::localtime(&t);;

int ebc_cnt = 0;
int ebc_fail = 0;
std::tm ebc_begin = *std::localtime(&t);;

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
std::string clientUrl[3];
