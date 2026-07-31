// SN:32`LX>m?Ebe`Z]<o
// File(/data/room/convoy/yishiting.c) of convoy's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是彗星主人擎天柱和重要人物商量江湖大事之处，正中有不
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

        set("room_owner", "擎天柱");
        set("room_name", "彗星");
        set("room_id", "convoy");
        set("room_owner_id", "convoy");
        set("room_position", "青砖路");
}
