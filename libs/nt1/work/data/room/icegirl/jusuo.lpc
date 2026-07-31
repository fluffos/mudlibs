// SN:?Ke^TASJh0HZ=TUn
// File(/data/room/icegirl/jusuo.c) of icegirl's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是剑冢主人寒玉儿休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "寒玉儿");
        set("room_name", "剑冢");
        set("room_id", "ice");
        set("room_owner_id", "icegirl");
        set("room_position", "山路");
}
