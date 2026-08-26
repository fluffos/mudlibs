#ifndef __SYS__LOG
#define __SYS__LOG

#define ERROR_LOG "ERROR_REPORTS"
#define PLAYER_ERROR_LOG "BUGS"
#define LOG_FILE "/log/ERRORS"
#define TEMP_MAIL_LIST "/w/" + this_player()->query_name() + "/TEMP_MAIL_LIST"
#define TEMP_FORWARD_LIST "/w/" + this_player()->query_name() + "/TEMP_FORWARD_LIST"
#define SMART_LOG "/std/smart_log"

#define WWW_TEMP_MAIL_LIST "/w/" + user + "/TEMP_MAIL_LIST"
#define WWW_TEMP_FORWARD_LIST "/w/" + user + "/TEMP_FORWARD_LIST"

#endif /* __SYS__LOG */
