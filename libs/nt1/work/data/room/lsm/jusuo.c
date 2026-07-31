// SN:IF4a9^9cEoN8mn6j
// File(/data/room/lsm/jusuo.c) of lsm's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是雷神之殿主人雷斯魔休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "雷斯魔");
        set("room_name", "雷神之殿");
        set("room_id", "lsm");
        set("room_owner_id", "lsm");
        set("room_position", "平原小路");
}
