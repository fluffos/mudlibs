// SN:HlJ>SSPNW=HmMW0j
// File(/data/room/tanger/yishiting.c) of tanger's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是唐二居主人唐二和重要人物商量江湖大事之处，正中有不
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

        set("room_owner", "唐二");
        set("room_name", "唐二居");
        set("room_id", "tangr");
        set("room_owner_id", "tanger");
        set("room_position", "碎石小道");
}
