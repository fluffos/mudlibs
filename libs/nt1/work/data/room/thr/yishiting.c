// SN:Wbm^CS;lG8LQ]RAN
// File(/data/room/thr/yishiting.c) of thr's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是二班主人阿二和重要人物商量江湖大事之处，正中有不少
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

        set("room_owner", "阿二");
        set("room_name", "二班");
        set("room_id", "erban");
        set("room_owner_id", "thr");
        set("room_position", "青石官道");
}
