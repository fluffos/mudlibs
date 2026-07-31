// SN:K_@Xo\4\Z9KE3T11
// File(/data/room/levatin/yishiting.c) of levatin's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是风中的雪花主人慕容伤和重要人物商量江湖大事之处，正
中有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "慕容伤");
        set("room_name", "风中的雪花");
        set("room_id", "piaodd");
        set("room_owner_id", "levatin");
        set("room_position", "碎石小道");
}
