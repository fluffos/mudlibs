// SN:kFYo6RdNmchPcJW?
// File(/data/room/one/jusuo.c) of one's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天上人间主人不二休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "不二");
        set("room_name", "天上人间");
        set("room_id", "tshrj");
        set("room_owner_id", "one");
        set("room_position", "碎石小道");
}
