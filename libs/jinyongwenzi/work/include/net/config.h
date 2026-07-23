#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include "net/services.h"
#endif

/* These are the primary and secondry hosts to use as boot servers
 * for the DNS. It is better to set to the primary to be a mud on
 * the same continent.
 */
// Elon (07-01-95) updated LISTNODES to current
// The TMI-2
#define MUDLIST_DNS ({ "202.97.175.44", 6670 })
// The Eastern Stories
#define MUDLIST_BAK ({ "202.97.175.44", 6670 })

#define LISTNODES ([ \
	"bxhn":		"202.100.222.125 8892",\
	"bxsj":		"202.100.254.146 8892",\
	"bxsy":		"202.107.35.25 8892",\
	"cd":		"202.115.135.222 5559",\
	"cq":		"203.93.111.167 5559",\
	"gz":		"202.98.196.10 5559",\
	"hb":		"202.99.160.83 5559",\
	"hn":		"202.100.222.86 5559",\
	"ln":		"202.97.175.44 5559",\
	"qd":		"61.156.35.5 6670",\
	"qhd":		"202.99.170.30 5559",\
	"sd":		"61.156.35.5 5559",\
	"sh":		"202.101.165.165 6670",\
	"sy":		"202.107.35.22 5559",\
	"sy2":		"202.107.35.22 6670",\
	"yt":		"61.156.14.135 5559",\
	"zj":		"202.101.165.165 5559"\
])

/* This is the default packet size of outgoing mail messages. The ideal
 * number is 512, maximum would be about 900, since 1024 is the maximum
 * udp packet size. Probably best kept at 512
 */
#define MAIL_PACKET_SIZE 512

/* These macros are for the name service. They determine how often the
 * database is refreshed, how often other muds are checked, how often
 * the sequence list is checked for timed out services, and how long a
 * service is allowed to time out.
 */
#define REFRESH_INTERVAL 5*60
#define PING_INTERVAL 30*60
#define SEQ_CLEAN_INTERVAL 60*60
#define SERVICE_TIMEOUT 30

/* The number of muds that we initialy allocate space for. This speeds
 * up name lookup.
 */
#define MUDS_ALLOC 60

/* This macro controls the level of tcp support used by the mud for
 * services such as finger, tell and mail. Valid values are:
 * TCP_ALL - all services available
 * TCP_ONLY - only tcp services available
 * TCP_SOME - some tcp services are available
 * TCP_NONE - no tcp services available
 */
#define TCP_SERVICE_LEVEL TCP_ALL

/* These are the prefered protocols used for certain services which can
 * be done either way. Mail should be left tcp, the others are up to
 * the individual admin. If the one you choose is not supported the
 * other type _may_ be used depending on the service.
 */

#define PREF_MAIL SVC_TCP
#define PREF_FINGER SVC_TCP
#define PREF_TELL SVC_UDP

/* These macros are used by the name server to keep a list of muds which
 * do not support the DNS.
 */
#define MUD_ADDRESSES "/adm/etc/mud_addresses"
#define MUD_SERVICES "/adm/etc/mud_services"

#endif //__NET__CONFIG_H
