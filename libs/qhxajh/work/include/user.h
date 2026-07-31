// user.h
#ifndef __USER__
#define __USER__

// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD			1
#define DUMP_IDLE				2

// Kick out net-dead users in 15 minutes
#define NET_DEAD_TIMEOUT		 900

// Kick out idle users in 20 minutes
#define IDLE_TIMEOUT			1200

// 一个playerMUD里一年的实际时间。 
// 实际的12小时是MUD里的一年。
#define BASE_TIME               86400

#endif
