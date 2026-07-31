// SN:bQYZQL=Alg;PYj6E
// File(/data/room/gmyr/yishiting.c) of gmyr's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是流浪居主人伊人古墓和重要人物商量江湖大事之处，正中
有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "伊人古墓");
        set("room_name", "流浪居");
        set("room_id", "gmyr");
        set("room_owner_id", "gmyr");
        set("room_position", "三岔口");
}
