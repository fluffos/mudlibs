// SN:=MkEk7fYfn6?VFKc
// File(/data/room/aoa/jusuo.c) of aoa's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是幽宅主人死囚休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "死囚");
        set("room_name", "幽宅");
        set("room_id", "you");
        set("room_owner_id", "aoa");
        set("room_position", "名人堂");
}
