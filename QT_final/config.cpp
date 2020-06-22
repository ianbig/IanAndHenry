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
std::atomic<int> total_count;
std::tm begin_time = *std::localtime(&t);
std::atomic<int> failure_count;

/**Workload */
std::string clientA_name = "A";
std::string clientB_name = "B";
std::string clientC_name = "C";
int total_A = 10000;
int total_B = 10000;
int total_C = 10000;

/**Website info */
std::atomic<int> wind_cnt;
std::atomic<int> wind_fail;
std::tm wind_begin = *std::localtime(&t);;

std::atomic<int> ebc_cnt;
std::atomic<int> ebc_fail;
std::tm ebc_begin = *std::localtime(&t);;

std::atomic<int> ettoday_cnt;
std::atomic<int> ettoday_fail;
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
