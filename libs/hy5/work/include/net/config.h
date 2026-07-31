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
#define MUDLIST_DNS  ({ "211.99.38.214",5559})
// The Eastern Stories
#define MUDLIST_BAK  ({ "211.99.38.214",5559})

#define LISTNODES ([ \
     "武林争霸II" : "61.128.193.35 5559",\
     "海洋II" : "202.101.10.243 5559",\
     "鹿鼎记" : "202.101.10.243 8892",\
     "大话西游" : "202.101.10.243 6670",\
     "海洋II上海2站" : "202.101.10.243 10003",\
     "云起云落" : "202.109.249.9 5559",\
     ])

#define BANDLIST ([\
"Mud1" : "202.104.151.252 5559",\
"Mud2" : "61.156.17.111 2003",\
"Mud3" : "202.101.98.168 4003",\
"Mud4" : "61.128.218.75 8892",\
"Mud5" : "210.43.176.7 8004",\
"Mud6" : "202.109.73.244 6670",\
"Mud7" : "61.156.20.8 8892",\
"Mud8" : "61.128.218.75 6670",\
"Mud9" : "202.103.160.97 5004",\
"Mud10" : "202.96.91.22 8004",\
"Mud11" : "202.109.73.244 6670",\
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
