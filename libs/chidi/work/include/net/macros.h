//  This file contains useful network macros.
#ifndef __NET__MACROS_H
#define __NET__MACROS_H

#include <mudlib.h>

#ifndef DNS_MASTER
#include <net/daemons.h>
#endif

// for converting hostnames in the host representation to the
// network representation and vice-versa
#define htonn(x) replace_string(lower_case((x)?(x):"")," ",".")
#define nntoh(x) capitalize(replace_string((x)?(x):"","."," "))
#define ntoh(x) capitalize(replace_string((x)?(x):""," ","."))

// macros for getting resources
// dns_master (sockets package, absent under WASM -- AGENTS.md 1.3c/7.6)
// never loads there; Mud_name() is called unconditionally from many
// unrelated places (channeld.lpc, emoted.lpc chat lines, ...), so it
// must not assume the daemon exists. query_mud_name() just returns the
// compile-time INTERMUD_MUD_NAME constant, so fall back to it directly
// (same upper_case(ntoh(...)) transform the daemon path applies).
#define Mud_name() (string)upper_case(ntoh(find_object(DNS_MASTER) ? DNS_MASTER->query_mud_name() : INTERMUD_MUD_NAME))
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

#define ACCESS_CHECK(x) ((!x)||(geteuid((x)) == ROOT_UID))

// for logging and stuff
#define dns_log(x, y)   DNS_MASTER->aux_log((x), (y))
#define dns_warning(x)  DNS_MASTER->aux_warning((x))

#endif //__NET__MACROS_H
