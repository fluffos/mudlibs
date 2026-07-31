// SN:MU>Zn7mZ<O7:?j:l
// File(/data/room/hun/yishiting.c) of hun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是鬼岛主人鬼魂和重要人物商量江湖大事之处，正中有不少
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

        set("room_owner", "鬼魂");
        set("room_name", "鬼岛");
        set("room_id", "dao");
        set("room_owner_id", "hun");
        set("room_position", "三岔口");
}
