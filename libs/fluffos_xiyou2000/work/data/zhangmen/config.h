#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include <net/services.h>
#endif

/* These are the primary and secondry hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// 11-1-95
// ES
#define MUDLIST_DNS ({ "202.96.134.136", 3991 })
// enchanted rock

#define MUDLIST_BAK ({ "202.96.134.136", 4004 })

#define LISTNODES ([ \
"HH": "61.138.37.101   6668", \
"CD": "202.103.101.13 6668",\
"SMX": "202.102.233.85 6668",\
"KF":"61.128.103.112 4446",\
"HY": "202.102.233.85 8890",\
"YUDIAN"  : "202.107.225.58 6668",\
"HIT": "202.118.246.111 8890",\
"ZX":  "61.132.93.194 6668",\
"ZT": "202.112.115.94  6668", \
"SK":  "61.141.216.74 6668",\
"QD":  "211.97.168.157 6668",\
])

/* These IP are not welcome
 * add by ken@chinesemud.net
 */
#define BANDLIST ([\
"dtxy" : "61.134.12.112 2004" ,\
"ys.bj" : "210.77.145.223",\
"xhc" : "202.96.144.141 5559",\
"jxqy" : "61.139.29.94 6670" ,\
])

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

/* These IP are for Big5 chinese codes 
 * add by ken@chinesemud.net
 */
#define Big5IP ({ "140","192","207","209","203", "210", "129", "208", "205", "206" })

#endif //__NET__CONFIG_H



