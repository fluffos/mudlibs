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
#define MUDLIST_DNS ({ "202.96.199.144", 5559})

#define MUDLIST_BAK  ({ "61.132.62.131", 2003})

#define LISTNODES ([ \
	"TXH-SD":	"202.102.136.72 3337",\
	"SH":		"202.96.236.99 7781",\
	"HB":		"210.72.21.12 5559",\
	"LDJ2000":      "202.99.166.21 6670",\
	"WLWS":         "61.132.62.131 2003",\
	"LDJ":          "202.103.25.171 4004",\
	"JYQXZ":	"10.110.110.1 4003",\
	"XAJH2":	"172.21.16.136 4004",\
	"FYZQ1":	"10.103.68.165 7781",\
	"XIAN.ES2":	"202.130.26.8 6266",\
	"LDJ.TS":    	"202.99.166.21 2004",\
	"SKY_SNOW.NN":  "202.103.237.132 5555",\
	"SKY_SNOW.FS":	"202.105.24.59 5555",\
	"FYZQ":		"10.103.68.165 7781",\
	"LDJ.XA":	"202.100.30.11 4448",\
	"WLZBII":       "61.128.193.35 5559",\
	"CCTX.GY":	"10.157.11.254 6973",\
	"XAJH2.EAST":	"202.96.125.121 4004",\
	"SY":		"10.36.32.110 5559",\
	"WLQY.GY":      "10.157.11.194 6670",\
	"TXH":		"61.132.52.229 3337",\
	"WLWS-CS":      "202.103.108.241 2003",\
	"THE.STORY.OF.HERO":"202.101.98.168 4003",\
	"JHFY":		"10.143.50.232 6670",\
	"LDTX":		"202.100.30.11 2004",\
	"J.H.Y.J":	"10.143.50.232 2004",\
	"SNOWSWORD":	"202.109.72.47 3337",\
	"JMYX":		"202.103.108.241 5559",\
])
/* These IP are not welcome, because they flood es channel but nody control it
 * add by ken@chinesemud.net
 */

#define BANDLIST ([\
	"XAJH2":     "202.96.134.136 4004",\
	"TYMYD":     "10.63.52.29 8892",\
	"ZHWIZ":     "10.63.201.147 8892",\
	"WLWS-KF":   "10.74.47.10 4004",\
	"JMYX-WIZ":  "10.62.170.36 8892",\
	"ZHKF":	     "10.63.53.22 8892",\
	"YMH":	     "172.20.28.89 10003",\
	"RORO":	     "10.143.203.12 5559",\
	"WLZBII-WIZ":"61.128.193.35 5054",\
	"SAY.HERO.WHO.IS.HERO": "172.18.59.48 5559",\
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
#define PING_INTERVAL       20*60
#define SEQ_CLEAN_INTERVAL  20*60
#define SERVICE_TIMEOUT        60

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
