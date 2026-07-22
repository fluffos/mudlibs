#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H
#ifndef SVC_TCP
#include <net/services.h>
#endif
/* These are the primary and secondry hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// Elon (07-01-95) updated LISTNODES to current
// The TMI-2
#define MUDLIST_DNS  ({ "202.98.117.28", 6670 })
// The Eastern Stories
#define MUDLIST_BAK ({ "202.100.26.22",6670 })
#define LISTNODES ([ \
"jhfy2"      : "210.77.169.154 6670",\
"ldj.ts"    : "202.99.166.21 2004",\
"xi'an.ldj" : "202.100.30.11 4448",\
"ldj"       : "202.103.25.171 4004",\
"fengchen":"202.103.160.58 4004", \
"ldj-ts":"202.99.166.21 2349", \
"ldj-ts2":"202.98.117.28 2004",\
"CCTX.GY":"10.157.11.254 6973",\
"FYZQ1":"10.103.68.165 7781",\
"JYQXZ":"10.110.110.1 4003",\
"SY":"10.36.32.110 5559",\
"TXH":"61.132.52.229 3337",\
"WLCQ":"10.64.100.1 5559",\
"WLQY.GY":"10.157.11.194 6670",\
"WLWS":"61.132.62.131 2003",\
"WLZBII":"61.128.193.35 5559",\
"XAJH2.EAST":"202.96.125.121 4004",\
"YXCS":"202.130.26.8 6266",\
"YXXZ":"172.20.16.109 5559",\
"MH":"202.98.117.33 5559",\
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
#endif //__NET__CONFIG_H
