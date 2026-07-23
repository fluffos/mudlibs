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
#define MUDLIST_DNS  ({ "202.101.100.209", 7478 })
#define MUDLIST_BAK  ({ "202.101.100.209", 5559 })
#define MUDLIST_BAK  ({ "61.170.130.89", 5559 })
#define MUDLIST_BAK  ({ "211.91.27.134", 5559 })
#define MUDLIST_BAK  ({ "211.91.27.134", 8892 })
// The Eastern Stories
#define MUDLIST_BAK  ({ "140.113.204.42", 8008 })
#define MUDLIST_BAK ({"193.10.174.41", 5563})
#define MUDLIST_BAK ({"209.191.135.218",5559})
#define MUDLIST_BAK ({"209.191.135.218",2229})

#define LISTNODES ([ \
        "B"           :       "211.91.27.134 5559", \
        "T"           :       "211.91.27.134 7478", \
        "C"           :       "211.91.27.134 8892", \
        "OPN"           :       "202.101.100.209 5559", \
        "DEV"           :       "202.101.100.209 7478", \
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
