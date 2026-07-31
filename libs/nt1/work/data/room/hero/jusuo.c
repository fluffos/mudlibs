// SN:6Dm2oi@g4NU5gTHV
// File(/data/room/hero/jusuo.c) of hero's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是英雄会馆主人英雄休息、读书的地方。楼上就是主人的卧
室，西面则是书房。 
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
    
        set("room_owner", "英雄");
        set("room_name", "英雄会馆");
        set("room_id", "hero");
        set("room_owner_id", "hero");
        set("room_position", "树林");
}
