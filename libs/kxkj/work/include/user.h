// user.h
//test
#ifndef __USER__
#define __USER__

// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD			1
#define DUMP_IDLE				2

// Kick out net-dead users in 5 minutes
#define NET_DEAD_TIMEOUT		 300

// Kick out idle users in 10 minutes
// 取消发呆踢人
// #define IDLE_TIMEOUT			600

#endif
