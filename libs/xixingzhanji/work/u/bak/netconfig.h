#ifndef __NET__CONFIG_H
#define __NET__CONFIG_H

#ifndef SVC_TCP
#include <net/services.h>
#endif

/* These are the primary and secondry hosts to use as boot servers
 * for the DNS.  It is better to set to the primary to be a mud on
 * the same continent.
 */
// 11-1-95
// ES
#define MUDLIST_DNS ({ "202.96.144.199",8892 })
// enchanted rock
#define MUDLIST_BAK ({ "202.96.144.199",5559 })

#define LISTNODES ([ \
        "1.XSSX":"61.156.20.8 8892",\
        "61.134.49.11":"61.134.49.11 2004",\
        "CELESTIAL.KY":"202.103.160.97 4004",\
        "CQDX-XYJ2000":"61.128.218.75 6670",\
        "CS":"61.137.127.208 6670",\
        "DHXY-YN":"202.156.44.141 6670",\
        "DJX":"202.98.196.68 5559",\
        "DJX.SH":"61.129.64.137 5559",\
        "FALLING-SUN":"202.103.184.38 5559",\
        "FALLING-SUN_STAR":"202.98.164.22 5559",\
        "FENGCHEN2":"202.103.160.97 5004",\
        "HC":"210.78.145.67 5559",\
        "HC.NEW":"210.78.145.67 8892",\
        "HELL.ANCIENT":"202.96.144.141 4004",\
        "HELL.BN":"202.115.24.88 2004",\
        "HELL.EM":"202.102.245.60 2004",\
        "HELL.ES":"203.93.95.159 2004",\
        "HELL.FR":"61.166.155.144 2004",\
        "HELL.RV":"202.96.144.141 2004",\
        "HELL.SF":"202.98.6.138 2004",\
        "HELL.SG":"61.132.62.131 2004",\
        "HELL.SR":"202.96.109.11 2004",\
        "HELL.WS":"202.100.72.21 2004",\
        "HELLFIRE":"202.98.191.208 6973",\
        "JX-FZ":"202.101.234.104 6670",\
        "JX_XYJ":"202.101.231.87 6670",\
        "JHFY":"61.129.64.139 2013",\
        "JHFY-III":"202.103.21.247 2013",\
        "JMYX":"61.137.93.73 5559",\
        "JYQX.SD":"202.104.30.132 5559",\
        "JYQXII":"61.133.95.11 2003",\
        "LDJ":"202.103.25.171 4004",\
        "LDJ.CD":"61.139.82.186 4004",\
        "LDJ.CD":"61.139.82.139 4004",\
        "LDJ.CQ":"61.128.193.72 8892",\
        "LDJ.HN":"202.102.231.41 4004",\
        "LDJ.HUBEI":"202.103.52.192 4004",\
        "LDJ.HUNAN":"61.128.193.72 4004",\
        "LDJ.JINQIAO":"61.158.225.136 4004",\
        "LDJ.SZ":"61.144.249.125 2004",\
        "LDJ.ZJ":"61.133.89.227 4004",\
        "LEGEND.SH":"61.129.64.139 3337",\
        "MX":"61.133.95.11 2004",\
        "SDXYZ":"61.128.218.75 8892",\
        "SEAL.OF.DOOM":"211.72.114.50 4004",\
        "SJPLII-LN":"202.96.87.50 5559",\
        "SILVERSAND_MUD":"202.96.140.58 4448",\
        "SKY_SNOW.FS":"202.105.24.59 5559",\
        "SMLW-YC":"61.150.240.172 4004",\
        "SMLW-ZZ":"202.103.98.74 2004",\
        "SXXYJ":"202.101.234.156 6670",\
        "SYXJL":"202.102.230.25 5559",\
        "szutx":"210.39.3.34 5004",\
        "THE.STORY.OF.HERO":"202.101.98.168 4003",\
        "TZCQ":"202.103.19.59 8892",\
        "WLFZ":"202.100.13.169 5559",\
        "WLLZI.SD":"61.133.95.11 2004",\
        "WLLZII.FH":"202.104.16.44 2004",\
        "WLWS":"61.132.62.131 2003",\
        "WLWS-CS":"61.137.93.73 2003",\
        "WLZBII":"61.128.193.35 5559",\
        "XK2000":"202.98.8.6 6670",\
        "XLQY":"202.109.183.3 4004",\
        "XHC2.ST":"202.96.144.199 8892",\
        "XHC.FY":"202.96.144.141 5559",\
        "YQYL":"202.109.249.9 5559",\
        "YSYX":"61.132.118.51 5559",\
        "YSZZ.LN":"202.96.91.22 8004",\
        "YSZZ.SH":"202.109.73.244 6670",\
        "YSZZ.华中":"202.114.20.6 6004",\
        "YTTL.CQ":"61.128.193.72 8892",\
        "YXLZMUD":"61.133.95.11 5559",\
        "ZHSH":"202.103.98.74 5004",\
        "ZHWL":"202.98.198.81 4006",\
        "ZHYX":"211.66.105.10 5559",\
        "ZWBS":"61.143.97.134 6670",\
        "jz":"202.104.32.221 3337",\
        "XYY":"61.139.81.110 8892",\
        "XXZJ":"61.139.81.110 5559",\
        "SILVERSAND_MUD.II":"202.96.140.90 2004",\
        "JHFY-EDU":"202.193.67.32 5004",\
        "FXJH":"61.139.60.108 6670",\
        "FSYY":"61.137.127.208 4004",\
        "HLG":"202.118.192.200 5559",\
        "XKJH":"61.156.25.6 5559",\
])
/* These IP are not welcome
 * add by ken@chinesemud.net
 */
#define BANDLIST ([\
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
#define SERVICE_TIMEOUT 30

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

#define PREF_MAIL        SVC_TCP
#define PREF_FINGER       SVC_TCP
#define PREF_TELL        SVC_UDP

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
