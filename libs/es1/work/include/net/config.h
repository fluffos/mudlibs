#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#include <uid.h>
#ifndef SVC_TCP
#include "net/services.h"
#endif

/* These are the generally reliable hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// Elon@ES 11-25-94, updated to current.
#define LISTNODES ([ \
	"Celestial Empire" : "140.113.122 223 4004", \
        "ES2 US"      : "165.227.52.1 4004",\
        "TMI-2"       : "129.10.114.86 5563", \
        "shadowriver" : "204.122.16.44 5008", \
        "circle"      : "192.31.87.57 4451", \
       "nightmare"    : "199.199.122.10 1709", \
       "paradox.ii"   : "129.32.32.120 1699", \
     ])


/* This should never be changed. */
#define MAX_PACKET_SIZE	1024

/* Set this to be the time that shall pass before a mud that we haven't
  heard anything from is removed from the dynamic list. */
#define MAX_NO_CONTACT	60*60*12

/* This is the default packet size of outgoing mail messages.  The ideal
 * number is 512, maximum would be about 900, since 1024 is the maximum
 * udp packet size.  Probably best kept at 512
 */
#define MAIL_PACKET_SIZE        (MAX_PACKET_SIZE/2)
 
/* These macros are for the name service.  They determine how often the
 * database is refreshed, how often other muds are checked, how often
 * the sequence list is checked for timed out services, and how long a
 * service is allowed to time out.
 */
#define REFRESH_INTERVAL     45*60
#define PING_INTERVAL       60*2*60
#define SEQ_CLEAN_INTERVAL  5*60
#define SERVICE_TIMEOUT        30

/* The number of muds that we initialy allocate space for.  This speeds
 * up name lookup.
 */
#define MUDS_ALLOC 70

/* This macro controls the level of tcp support used by the mud for
 * services such as finger, tell and mail. Valid values are:
 *  TCP_ALL   - all services available
 *  TCP_ONLY  - only tcp services available
 *  TCP_SOME  - some tcp services are available
 *  TCP_NONE  - no tcp services available
 */
#define TCP_SERVICE_LEVEL TCP_ALL

#endif //__NET__CONFIG_H
