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
#define MUDLIST_DNS ({ "202.96.134.136", 3991 })
//#define MUDLIST_DNS  ({ "210.39.0.33", 6368 })
//#define MUDLIST_DNS  ({ "210.34.3.133", 9030 })
// The Eastern Stories
#define MUDLIST_BAK ({ "202.96.134.136", 4004 })
//#define MUDLIST_BAK  ({ "140.113.204.42", 8008 })
//#define MUDLIST_BAK  ({ "210.34.3.136", 2200 })
#define BANDLIST ([\
])
#define ADM_EMAIL "evilgod@163.net"
#define MUDLIB_WEB   "http://bbs.szu.edu.cn:6080/"
#define LISTNODES ([ \
        "Eastern Stories II"   : "159.226.43.19 6872",\
        "xinjiapo xyj"      :    "137.132.19.24 6670",\
        "zhuhai xyj"      :    "202.96.132.68 6670",\
        "sh xyj"      :    "202.96.236.99 6670",\
        "xm xyj"      :    "202.101.106.246 6670",\
        "hz xyj"      :    "210.32.147.8 6670",\
        "jnumud"  :   "202.116.9.61 4004",\
        "xo"      :    "203.93.69.203 4004",\
        "tsinghua xo"      :    "202.112.55.68 4004",\
        "huazhong xo"      :    "202.114.2.3 4004",\
        "chengdu xo"      :    "202.98.99.180 4004",\
        "zhongshan"   : "172.25.16.100 5559", \
        "xiaoao"   : "172.21.16.136 4004", \
        "shendiao": "202.103.237.132 6670", \
        "zhongsan": "172.25.16.100 5559", \
        "vargonmud" : "128.220.24.36 5563", \
        "xajh2" : "172.21.16.136 4004",\
        "xy" : "172.117.29.98 5559",\
        "hzfy" : "202.96.98.134 3378",\
     ])
#define HOST_ADDRESS2 	"172.21.24.100"
#define Big5IP ({ "140","192","207","209","203", "210", "129", "208", "206" })

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
#define REFRESH_INTERVAL     5*60
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
