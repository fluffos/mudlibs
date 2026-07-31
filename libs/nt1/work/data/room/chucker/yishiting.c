// SN:^3goDi>AliK3nI0o
// File(/data/room/chucker/yishiting.c) of chucker's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是嘎嘎居主人段嘎嘎和重要人物商量江湖大事之处，正中有
不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "段嘎嘎");
        set("room_name", "嘎嘎居");
        set("room_id", "chucker");
        set("room_owner_id", "chucker");
        set("room_position", "树林");
}
