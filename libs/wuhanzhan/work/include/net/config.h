#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include "net/services.h"
#endif

/* These are the primary and secondry hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// Elon (07-01-95) updated LISTNODES to current
// The TMI-2
#define MUDLIST_DNS  ({ "193.10.174.41", 5563 })
// The Eastern Stories
//#define MUDLIST_BAK  ({ "140.113.204.42", 8008 })
//              "zd": "210.32.147.8 4448", \ 
#define LISTNODES ([ \
     "xyj": "209.83.132.67 6670", \
     "xf": "61.136.152.43 8892", \
"cs-ii":"10.62.1.195 8892",\
     "xa": "61.134.4.61 6670",\
"SQ": "10.70.129.9 6670",\
"SQ2": "10.70.129.9 8892",\
"fx": "202.96.91.22 6670",\
"hb": "202.103.45.19 8892",\
                "hell":"202.103.134.223 4004",\
     "zz": "202.102.245.25 6670", \
     "xm": "202.101.104.234 6670", \
"xm-i": "202.101.106.246 6670",\
"zh": "202.105.177.101 6670",\
     "sy": "202.118.29.99 6670", \
     "heb": "202.118.226.55 6670", \
     "gy": "202.98.193.241 6670", \
     "dl": "202.118.66.15 6670", \
     "bj": "202.84.16.35 6670", \
     "qd": "203.93.95.127 6670", \
"qh":"166.111.9.5 6670",\
"yc": "202.103.6.38 6670",\
     "xj": "61.128.97.133 6670", \
"sz":"202.102.14.20 6670",\
"xbsk": "202.100.72.21 6670",\
     "sy": "202.118.29.99 6670", \
"hb":"61.136.152.56 8892",\
"shxyj":"202.96.236.99 6670",\
     "sh": "202.96.236.99 6670", \
     "fz": "202.109.192.10 6670", \
     "zh": "202.96.132.68 6670", \
     "zd": "210.32.134.188 6670", \
     "lz": "202.100.72.21 6670", \
     "hz": "202.101.165.130 6670", \
     "xajh": "202.96.134.136 7004", \
     "test": "130.126.160.111 6670",\
     ])

        //      "hero.story2": "202.102.245.12 6670",\

/* This is the default packet size of outgoing mail messages.  The ideal
 * number is 512, maximum would be about 900, since 1024 is the maximum
 * udp packet size.  Probably best kept at 512
 */
#define MAIL_PACKET_SIZE        512
 
/* These macros are for the name service.  They determine how often the
 * database is refreshed, how often other muds are checked, how often
 * the sequence list is checked for timed out services, and how long a
 * service is allowed to time out.
 */
#define REFRESH_INTERVAL    30*60
#define PING_INTERVAL       30*60
#define SEQ_CLEAN_INTERVAL  60*60
#define SERVICE_TIMEOUT        30

/* The number of muds that we initialy allocate space for.  This speeds
 * up name lookup.
 */
#define MUDS_ALLOC 60

/* This macro controls the level of tcp support used by the mud for
 * services such as finger, tell and mail. Valid values are:
 *  TCP_ALL   - all services available
 *  TCP_ONLY  - only tcp services available
 *  TCP_SOME  - some tcp services are available
 *  TCP_NONE  - no tcp services available
 */
#define TCP_SERVICE_LEVEL TCP_ALL

/* These are the prefered protocols used for certain services which can
 * be done either way.  Mail should be left tcp, the others are up to
 * the individual admin.  If the one you choose is not supported the
 * other type _may_ be used depending on the service.
 */

#define PREF_MAIL         SVC_TCP
#define PREF_FINGER       SVC_TCP
#define PREF_TELL         SVC_UDP

/* These macros are used by the name server to keep a list of muds which
 * do not support the DNS.
 */
#define MUD_ADDRESSES   "/adm/etc/mud_addresses"
#define MUD_SERVICES    "/adm/etc/mud_services"

#endif //__NET__CONFIG_H

