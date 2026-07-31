// SN:YMIK:@iA8>:oVa:K
// File(/data/room/newerd/jusuo.c) of newerd's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是就是米主人就是米休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "就是米");
        set("room_name", "就是米");
        set("room_id", "newerd");
        set("room_owner_id", "newerd");
        set("room_position", "碎石小道");
}
