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
#define MUDLIST_DNS  ({ "61.132.93.196", 6670 })

#define MUDLIST_BAK  ({ "61.132.93.196", 3009 })

#define LISTNODES ([ \
"xhc-new" : "202.100.218.146 5559",\
"bh-I" : "202.96.140.58 4448",\
"bh-II" : "202.96.140.58 8892",\
"HELL.RV" : "202.104.242.79 2004",\
"HEROS.CD" : "61.139.77.194 3004",\
"FALLING-SUN" : "202.103.184.38 5559",\
"ZHYX" : "220.167.52.40 5559",\
"bh-II" : "218.246.32.136 2005",\
"ty" : "218.27.206.99 4004",\
"falling-sun" : "202.103.184.38 5559",\
"nt" : "61.184.100.7 2004",\
"tianya" : "211.97.200.87 4004",\
"hell.rv" : "202.104.234.74 2004",\
"rx" : "202.96.144.199 6670",\
"1.unknow.space" : "61.132.93.198 6670",\
"xajh2.east" : "202.96.162.88 7004",\
"falling-sun" : "210.78.159.141 6695",\
"wlws" : "61.132.74.241 2003",\
"jhfyii-sz" : "202.104.108.149 2013",\
"cosewin" : "202.96.144.141 8892",\
"1jyqxii.zb" : "61.156.17.111 2003",\
"jmyx" : "61.137.93.73 5559",\
"xyzx--xajh" : "210.78.159.146 6770",\
])

#define BANDLIST ([\
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

#define Big5IP ({ "140","192","207","209","203", "210", "129", "208", "206", "139" })

#endif //__NET__CONFIG_H

