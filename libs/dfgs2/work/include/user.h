// user.h
#ifndef __USER__
#define __USER__

#define F_AUTOLOAD	"/feature/user/autoload.lpc"
#define F_ALIAS		"/feature/user/alias.lpc"
#define F_EDIT		"/feature/user/edit.lpc"
#define F_MORE		"/feature/user/more.lpc"

// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD			1
#define DUMP_IDLE			2

// Kick out net-dead users in 15 minutes
#define NET_DEAD_TIMEOUT		900

// Kick out idle users in 20 minutes
#define IDLE_TIMEOUT			1200

#endif
