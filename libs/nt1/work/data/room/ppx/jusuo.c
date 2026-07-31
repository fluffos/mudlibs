// SN:dMf4gnVg5j65n_d3
// File(/data/room/ppx/jusuo.c) of ppx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是故居主人飘飘休息、读书的地方。楼上就是主人的卧室，
西面则是书房。 
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
    
        set("room_owner", "飘飘");
        set("room_name", "故居");
        set("room_id", "ppx");
        set("room_owner_id", "ppx");
        set("room_position", "三岔口");
}
