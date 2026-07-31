// SN:gX@898UbmMA<[^3o
// File(/data/room/waiting/jusuo.c) of waiting's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是等你一万年主人妹子等我休息、读书的地方。楼上就是主
人的卧室，西面则是书房。 
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
    
        set("room_owner", "妹子等我");
        set("room_name", "等你一万年");
        set("room_id", "waiting");
        set("room_owner_id", "waiting");
        set("room_position", "碎石小道");
}
