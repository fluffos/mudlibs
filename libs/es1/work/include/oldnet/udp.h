#ifndef __NET__UDP_H
#define __NET__UDP_H

#ifndef UDP_MASTER
#include "net/daemons.h"
#endif

#define UDP_PATH "/adm/daemons/network/udp/"

#define PING_Q     (UDP_PATH+"ping_q")
#define PING_A     (UDP_PATH+"ping_a")
#define MUDLIST_Q  (UDP_PATH+"mudlist_q")
#define SUPPORT_Q  (UDP_PATH+"support_q")
#define STARTUP    (UDP_PATH+"startup")
#define SHUTDOWN   (UDP_PATH+"shutdown")

/*
 * We need the ip number, the current socket efuns don't handle using names.
 */
#define MUDLIST_UDP  ({ "146.101.64.2", 4250 }) // discworld
#define MUDLIST_BAK  ({ "129.16.79.12", 2508 }) // genesis

/* The currently known types */
#define UDP_STARTUP "startup"
#define UDP_SHUTDOWN "shutdown"
#define UDP_PING_Q "ping_q"
#define UDP_PING_A "ping_a"
#define UDP_SUPPORT_Q "support_q"
#define UDP_SUPPORT_A "support_a"
#define UDP_RWHO_Q "rwho_q"
#define UDP_RWHO_A "rwho_a"
#define UDP_MUDLIST_Q "mudlist_q"
#define UDP_MUDLIST_A "mudlist_a"
#define UDP_GFINGER_Q "gfinger_q"
#define UDP_AFFIRMATION_A "affirmation_a"
#define UDP_GFINGER_A "gfinger_a"
#define UDP_GWIZMSG "gwizmsg"
#define UDP_WARNING "warning"
#define UDP_GTELL "gtell"

/*
 * This is the number of retrys we ping the mud for before we decide
 * it has gone down.
 */
#define MAX_RETRYS 2
#define UDP_NO_CONTACT "_udp_no_contact"

#endif //__NET__UDP_H
