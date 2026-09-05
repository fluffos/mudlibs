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
//#define MUDLIST_DNS ({"159.226.253.8, 6666})
// The Eastern Stories
//#define MUDLIST_BAK  ({ "140.113.204.42", 8008 })
#define MUDLIST_BAK ({"193.10.174.41", 5563})


#define LISTNODES ([ \
        "8888" : "159.226.253.8 8892",\
        "暨大" : "202.116.9.61 4004",\
        "dunnowhere" : "202.117.118.11 4004",\
        "ZHTX" : "159.226.41.99 6872",\
         "ES2" : "202.200.37.35 4004",\
])

/* These IP are not welcome, because they flood es channel but nody control it
 * add by ken@chinesemud.net
 */
#define BANDLIST ([\
        "FengChen.Foshan" : "172.19.16.168 4004",\
        "CCTX1": "10.162.0.12 6973",\
        "CCTX2" : "10.163.180.2 7004", \
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
#define Big5IP ({ "140","192","207","209","203", "210", "129", "208", "206", "139" })

#endif //__NET__CONFIG_H
