/*
 * Imud 3 defines
 */
#ifndef _sys_imud3_h
#define _sys_imud3_h

#include "names.h"     // for domain

#define IMUD3 "etc/intermud3"

#define SERVICE_AUTH
#define SERVICE_CHANNEL
#define SERVICE_UCACHE
#define SERVICE_EMOTETO
#if 0    // we want to keep our files private
#define SERVICE_FILE
#endif
#define SERVICE_FINGER
#define SERVICE_LOCATE
#define SERVICE_MAIL
#define SERVICE_TELL
#define SERVICE_WHO

#define I3_ML_STATE       0
#define I3_ML_IPADDR      1
#define I3_ML_PPORT       2
#define I3_ML_TCPPORT     3
#define I3_ML_UDPPORT     4
#define I3_ML_MUDLIB      5
#define I3_ML_B_MUDLIB    6
#define I3_ML_DRIVER       7
#define I3_ML_MUDTYPE      8
#define I3_ML_OPENSTATE    9
#define I3_ML_ADMINEMAIL  10
#define I3_ML_SERVICES    11

/*
 * ugly macros - the less the better
 */
#define TEST_MUD_DOWN(x)   ((IMUD3->query_mud_info((x)))[I3_ML_STATE] > -1)
#define HAS_SERVICE(x,y)   ((muds[(x)][I3_ML_SERVICES][(y)]))

#define MUDNAME         (capitalize(DOMAIN))
#define MAX_TTL         5
#define MUDLIB          "Nirvanalib"
#define MUDLIB_VERSION  "stable"
#define DRIVER          "LDMud"
#define PORT_OOB        (query_udp_port() + 1)
#define PORT_UDP        query_udp_port()
#define PORT_FTP        3501
#define ADMIN_EMAIL     "nirvana_lpmud@yahoo.com"
#define MUD_STATUS      "Open to players"
#define SAVE_INTERMUD   "/save/intermud3"
#define MAX_SEND        247
#define MAX_CONNECTIONS 10

#endif
