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

// macros for getting resources
// dns_master (a sockets-package daemon, absent under WASM -- AGENTS.md
// 1.3c/7.6) never loads there, so DNS_MASTER->query_mud_name() throws
// "No program in object" -- and this macro is called unconditionally
// from many unrelated places (channeld.lpc's remove_addresses(), NPC
// chat/emote heart_beat()s, etc.), spamming a runtime error on every
// single call once the daemon is absent. query_mud_name() just returns
// the compile-time INTERMUD_MUD_NAME constant anyway (see dns_master.lpc),
// so fall back to it directly when the daemon isn't loaded.
#define Mud_name() (find_object(DNS_MASTER) ? (string)DNS_MASTER->query_mud_name() : INTERMUD_MUD_NAME)
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
