// SN:1YU9gkDBGlCiUS>j
// File(/data/room/flyernet/jusuo.c) of flyernet's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是桃花源主人大侠休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "大侠");
        set("room_name", "桃花源");
        set("room_id", "dragon");
        set("room_owner_id", "flyernet");
        set("room_position", "碎石小道");
}
