// SN:dX^WH]1T?OT<D;RK
// File(/data/room/riversun/yishiting.c) of riversun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是雅阁主人段小强和重要人物商量江湖大事之处，正中有不
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

        set("room_owner", "段小强");
        set("room_name", "雅阁");
        set("room_id", "riversun");
        set("room_owner_id", "riversun");
        set("room_position", "青砖路");
}
