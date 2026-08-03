// kl_r.h               昆仑派房间的头文件
// Ffox 98-9-7 9:29
#include <room.h>
#ifdef KL_DOOR
inherit DOOR_ROOM;
#else
inherit ROOM;
#endif
#include "kunlun.h"