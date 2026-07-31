// SN:2^HSZO0f42Y<1\NQ
// File(/data/room/miss/jusuo.c) of miss's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是湖水主人湖光休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "湖光");
        set("room_name", "湖水");
        set("room_id", "miss");
        set("room_owner_id", "miss");
        set("room_position", "三岔口");
}
