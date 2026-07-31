// SN:lY:A^n[JT8L81YMZ
// File(/data/room/walker/jusuo.c) of walker's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是巨型垃圾场主人拾荒者休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
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
    
        set("room_owner", "拾荒者");
        set("room_name", "巨型垃圾场");
        set("room_id", "ljc");
        set("room_owner_id", "walker");
        set("room_position", "碎石小道");
}
