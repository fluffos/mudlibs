// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//  This file contains useful network macros.
#ifndef __NET__MACROS_H
#define __NET__MACROS_H

#include <mudlib.h>

#ifndef DNS_MASTER
#include "net/daemons.h"
#endif

// for converting hostnames in the host representation to the
// network representation and vice-versa
#define htonn(x) replace_string(lower_case((x)?(x):"")," ",".")
#define nntoh(x) capitalize(replace_string((x)?(x):"","."," "))

// macros for getting resources
// WASM/local-play: DNS_MASTER is never preloaded and its create() does
// real resolve()/socket_create() work against a hardcoded remote
// intermud server -- avoid ever loading it just to render a name that
// is a constant anyway. Mud_name()/mud_nname() are the only uses of
// this header reached outside the (never-preloaded) network daemon
// family itself (checked via grep across the whole tree).
#define Mud_name() INTERMUD_MUD_NAME
#define mud_nname() htonn( Mud_name() )
#define mud_port() __PORT__
#define udp_port() (int)DNS_MASTER->query_udp_port()

// macros for the sequencer
#define index_add(x)     (int)DNS_MASTER->idx_request((x))
#define index_call(x,y)  (int)DNS_MASTER->idx_callback((x),(y))

// for security checking
#ifndef ROOT_UID
#include <uid.h>
#endif

//#define ACCESS_CHECK(x) ((!x)||(geteuid((x)) == ROOT_UID))
#define ACCESS_CHECK(x) (1)

// for logging and stuff
#define dns_log(x, y)   DNS_MASTER->aux_log((x), (y))
#define dns_warning(x)  DNS_MASTER->aux_warning((x))

#endif //__NET__MACROS_H
