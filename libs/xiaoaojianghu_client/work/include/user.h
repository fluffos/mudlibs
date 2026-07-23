// user.h
#ifndef __USER__
#define __USER__
// Signatures to tell user_dump() the reason to dump a user.
#define DUMP_NET_DEAD           1
#define DUMP_IDLE               2
// Kick out net-dead users in 15 minutes
#define NET_DEAD_TIMEOUT         600
// 自动断线时间20分钟
#define IDLE_TIMEOUT            1200

// // 一个playerMUD里一年的实际时间。 
// // 实际的24小时是MUD里的一年。
// 修改年龄的计算
// 具体说明在user.c中给出，不对其他的body进行修改
// 酱紫wiz改自己的年龄也比较方便
#define BASE_TIME_1             43200
#define BASE_TIME_2             86400
#define BASE_TIME_3             129600
#define BASE_TIME_4             172800

#define BASE_TIME               86400

#endif
