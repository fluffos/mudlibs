// SN:n@OKCTY@5o[XCaY9
// File(/data/room/yangkang/jusuo.c) of yangkang's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是北京城主人杨康休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "杨康");
        set("room_name", "北京城");
        set("room_id", "beijing");
        set("room_owner_id", "yangkang");
        set("room_position", "碎石小道");
}
