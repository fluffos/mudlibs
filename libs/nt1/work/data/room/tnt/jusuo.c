// SN:WaJ:e5?fDF7a20L=
// File(/data/room/tnt/jusuo.c) of tnt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是阳光华庭主人重庆休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "重庆");
        set("room_name", "阳光华庭");
        set("room_id", "tnt");
        set("room_owner_id", "tnt");
        set("room_position", "树林");
}
