//Last modified by waiwai@2001/05/04

#ifndef __USER__
#define __USER__

// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD			1
#define DUMP_IDLE				2

// Kick out net-dead users in 20 minutes
#define NET_DEAD_TIMEOUT		 1200
#define NET_DEAD_WIZOUT		 5

// Kick out idle users in 30 minutes
#define IDLE_TIMEOUT			1800

#endif
