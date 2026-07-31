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
#define MUDLIST_DNS  ({ "202.104.30.132", 2000 })
// enchanted rock
#define MUDLIST_BAK ({ "202.104.30.132", 2000 })
#define LISTNODES ([ \
"jyqx.sd":"202.104.30.132 5559",\
"DHXY":"61.134.4.234 6670",\
"DHXY-JS":"202.102.2.20 6670",\
"DHXY-JX":"202.109.183.3 6670",\
"DHXY-QD":"203.93.95.159 6670",\
"DHXY-SH":"202.109.72.40 8892",\
"DHXY-TW":"163.14.3.74   6670",\
"DHXY-ZJ":"202.96.109.11 8892",\
"LDJ":"202.103.25.171 4004",\
"LDJ.HN":"202.102.231.41 4004",\
"LDJ.SZ":"202.104.135.219 2004",\
"JMYX":"61.137.93.73 54",\
"XAJH2":"202.96.162.88 4004",\
"XJQX":"61.139.29.94 7781",\
"FALLING-SUN":"202.103.184.38 5559",\
"SNOWSWORD.WIZ":"61.129.64.138 3359",\
"JMYX":"61.137.93.73 5559",\
"LZHD":"61.128.193.72 5559",\
"XAJH2":"202.96.162.88 4004",\
"SNOWSWORD.SH":"61.129.64.138 3337",\
"SILVERSAND_MUD":"202.96.140.58 4448",\
"YS-ETERNAL":"202.178.133.140 8892",\
"YS-ETERNAL2":"203.107.56.136 4004",\
])

/* These IP are not welcome, because they flood es channel but nody control it
 * add by ken@chinesemud.net
 */

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

/* These IP are for Big5 chinese codes 
* add by ken@chinesemud.net
*/
#define Big5IP ({ "140","192","207","209", "129", "208", "206", "139", "202.178" })

#endif //__NET__CONFIG_H

