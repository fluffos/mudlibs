// SN:5GP^R[k_j5=>nj[@
// File(/data/room/toti/jusuo.c) of toti's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是盘龙居主人一笑挥刀休息、读书的地方。楼上就是主人的
卧室，西面则是书房。 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "一笑挥刀");
        set("room_name", "盘龙居");
        set("room_id", "panlongju");
        set("room_owner_id", "toti");
        set("room_position", "碎石小道");
}
