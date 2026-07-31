// SN:ZM[LW\WjBE@Egg8H
// File(/data/room/newall/jusuo.c) of newall's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是新居室主人新人类休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "新人类");
        set("room_name", "新居室");
        set("room_id", "xjs");
        set("room_owner_id", "newall");
        set("room_position", "青砖路");
}
