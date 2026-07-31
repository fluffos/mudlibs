// SN:Uhi6SRlel8L2:?j_
// File(/data/room/beidai/jusuo.c) of beidai's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是背篼主人背带休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "背带");
        set("room_name", "背篼");
        set("room_id", "beidai");
        set("room_owner_id", "beidai");
        set("room_position", "碎石小道");
}
