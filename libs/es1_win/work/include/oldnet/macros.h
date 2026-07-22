//  This file contains useful network macros.
#ifndef __NET__MACROS_H
#define __NET__MACROS_H

#ifndef DNS_MASTER
#include <net/daemons.h>
#endif

// for converting hostnames in the host representation to the
// network representation and vice-versa
#define htonn(x) replace_string(lower_case((x)?(x):"")," ",".")
#define nntoh(x) cap_words(replace_string((x)?(x):"","."," "))

// macros for getting resources
#define mud_nname() htonn( mud_name() )
#define mud_port() __PORT__
#define udp_port() (int)DNS_MASTER->query_udp_port()

// macros for the sequencer
#define index_add(x)     (int)DNS_MASTER->idx_request((x))
#define index_call(x,y)  (int)DNS_MASTER->idx_callback((x),(y))

// for security checking
#ifndef ROOT_UID
#include <uid.h>
#endif

#define ACCESS_CHECK(x) ((geteuid((x)) == ROOT_UID))

// for logging and stuff
#define dns_log(x, y)   DNS_MASTER->aux_log((x), (y))
#define dns_warning(x)  DNS_MASTER->aux_warning((x))

// I want to turn this into a simul_efun sometime
#ifndef Mud_name
#define Mud_name() capitalize( mud_name() )
#endif

#endif //__NET__MACROS_H
