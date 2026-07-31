// SN:0CSd9N^5bX:C\[gY
// File(/data/room/xsmzz/jusuo.c) of xsmzz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是小翠山轩主人张翠山休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "张翠山");
        set("room_name", "小翠山轩");
        set("room_id", "xsmzz");
        set("room_owner_id", "xsmzz");
        set("room_position", "碎石小道");
}
