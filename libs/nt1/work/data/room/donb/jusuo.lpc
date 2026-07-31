// SN:n_Y:MUY<:7WMOTPh
// File(/data/room/donb/jusuo.c) of donb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是幽游白书主人虚藏休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "虚藏");
        set("room_name", "幽游白书");
        set("room_id", "donb");
        set("room_owner_id", "donb");
        set("room_position", "碎石小道");
}
