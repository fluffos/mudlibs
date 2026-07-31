// SN:I6VjBmAXMYPLjIBS
// File(/data/room/gwhuo/jusuo.c) of gwhuo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是小鬼之家主人鬼舞火休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "鬼舞火");
        set("room_name", "小鬼之家");
        set("room_id", "gwhuo");
        set("room_owner_id", "gwhuo");
        set("room_position", "碎石小道");
}
