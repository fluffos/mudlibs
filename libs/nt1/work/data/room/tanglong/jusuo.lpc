// SN:GQ;oTjYTI3@R9OLG
// File(/data/room/tanglong/jusuo.c) of tanglong's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是苍龙之原主人唐龙休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "唐龙");
        set("room_name", "苍龙之原");
        set("room_id", "dragonsoul");
        set("room_owner_id", "tanglong");
        set("room_position", "碎石小道");
}
