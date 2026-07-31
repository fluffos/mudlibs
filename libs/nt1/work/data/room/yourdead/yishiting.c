// SN:M@Z[dK8h3M1hD:7n
// File(/data/room/yourdead/yishiting.c) of yourdead's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是龙潭主人渡会和重要人物商量江湖大事之处，正中有不少
桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "渡会");
        set("room_name", "龙潭");
        set("room_id", "yourdead");
        set("room_owner_id", "yourdead");
        set("room_position", "碎石小道");
}
