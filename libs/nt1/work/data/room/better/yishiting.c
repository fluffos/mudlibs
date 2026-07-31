// SN:2ndR[^b0<Ak`mdgj
// File(/data/room/better/yishiting.c) of better's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是颂经阁主人渡渡和重要人物商量江湖大事之处，正中有不
少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "渡渡");
        set("room_name", "颂经阁");
        set("room_id", "better");
        set("room_owner_id", "better");
        set("room_position", "三岔口");
}
