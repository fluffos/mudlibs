// SN:]5l?GlXS;F2MHe3e
// File(/data/room/levatin/jusuo.c) of levatin's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是风中的雪花主人慕容伤休息、读书的地方。楼上就是主人
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
    
        set("room_owner", "慕容伤");
        set("room_name", "风中的雪花");
        set("room_id", "piaodd");
        set("room_owner_id", "levatin");
        set("room_position", "碎石小道");
}
