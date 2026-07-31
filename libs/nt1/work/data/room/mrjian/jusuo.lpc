// SN:mek6cO4o^NY[@ImM
// File(/data/room/mrjian/jusuo.c) of mrjian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是灵光居主人慕容灵休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "慕容灵");
        set("room_name", "灵光居");
        set("room_id", "lgju");
        set("room_owner_id", "mrjian");
        set("room_position", "碎石小道");
}
