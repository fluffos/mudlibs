// Include File:/include/net/config.h

#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include "net/services.h"
#endif

// 这里是主 DNS 服务器和副 DNS 服务器。

#define MUDLIST_DNS  ({ "203.196.7.111",2230 })
#define MUDLIST_BAK  ({ "211.66.100.83", 2009 })

// 一开始联接的 MUD
/*
#define LISTNODES ([ \
	"FYTX.MH" : "203.196.7.111 2226",\
	"FALLING-SUN" : "202.103.184.38 5559",\
	"HELL.RV" : "202.96.144.141 2004",\
	"yinghao":"202.99.208.23 5559",\
	"silversand_mud:"202.96.140.58 4448",\
])*/
#define LISTNODES ([ \
     "wlzbII" : "61.128.193.35 5559", \
     "LDJ" : "202.103.25.171 4004",\
     "FALLING-SUN" : "202.103.184.38 5559",\
     "DJX" : "202.98.196.68 5559",\
     "HELL.ANCIENT" : "202.96.144.141 4004",\
     "JYQX.SD" : "202.104.30.132 5559",\
     "QYHC" : "61.136.136.83 8892",\
     "XKX.FORUTO" : "202.85.176.106 2003",\
     "XYY" : "61.139.81.110 8892",\
     "FYTX.MH" : "203.196.7.111 2226",\
])

// 禁止连接的 MUD
#define BANDLIST ([\
"cctx.gy":"10.157.11.254 6973",\
"cuterabbit":"10.163.180.6 7004",\
"cctx":"10.162.1.195 6973",\
])

// Big 码站点
#define Big5IP ({ "140","192","207","209","203", "210", "129", "208", "206", "139" })

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
