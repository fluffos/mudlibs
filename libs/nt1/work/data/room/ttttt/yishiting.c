// SN:<QDjS>3hZ=8[`T`;
// File(/data/room/ttttt/yishiting.c) of ttttt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是儿童乐园主人童童和重要人物商量江湖大事之处，正中有
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

        set("room_owner", "童童");
        set("room_name", "儿童乐园");
        set("room_id", "roomb");
        set("room_owner_id", "ttttt");
        set("room_position", "碎石小道");
}
