// SN:Yh@T;7PPM6j`<Df@
// File(/data/room/lting/jusuo.c) of lting's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是念婷小筑主人恋婷休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "恋婷");
        set("room_name", "念婷小筑");
        set("room_id", "lting");
        set("room_owner_id", "lting");
        set("room_position", "碎石小道");
}
