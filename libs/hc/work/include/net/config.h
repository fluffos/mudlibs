#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include "net/services.h"
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
"xajh" : "202.96.134.136 4004",\
"HCYX" : "202.100.218.146 65436",\
"herostory" : "202.99.168.30 2004",\
"ldj.wuhan" : "202.103.25.171 4004",\
"dhxyii" : "61.134.12.68 6670",\
])

/* These IP are not welcome
 * add by ken@chinesemud.net
 */

#define BANDLIST ([\
        "FengChen.Foshan" : "172.19.16.168 4004",\
         "DTXY" : "61.134.12.112 2004",\
        "JHII.MAIN" : "202.96.144.141 5559",\
          "jhii" : "61.128.193.36 5559",\
        "wlzbii" : "61.128.193.35 5559",\
  "ldj.wuhan" : "202.103.25.163 4004",\
 "The.Admin.Mud" : "140.119.75.11 5009",\
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
