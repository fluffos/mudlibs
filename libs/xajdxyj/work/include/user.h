// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// user.h
#ifndef __USER__
#define __USER__

// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD      1
#define DUMP_IDLE          2

// Kick out net-dead users in 15 minutes
// FoF change it to 3 minutes 2000-4-29
#define NET_DEAD_TIMEOUT      180

// Kick out idle users in 20 minutes
// FoF change it to 10 minutes 2000-4-29
#define IDLE_TIMEOUT        600

#endif
