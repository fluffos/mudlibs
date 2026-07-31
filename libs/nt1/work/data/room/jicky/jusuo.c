// SN:T[AHcTh9g121SkJ4
// File(/data/room/jicky/jusuo.c) of jicky's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是毛毛的家主人毛毛休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "毛毛");
        set("room_name", "毛毛的家");
        set("room_id", "jicky");
        set("room_owner_id", "jicky");
        set("room_position", "碎石小道");
}
