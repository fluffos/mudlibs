// SN:H70mQePjA1?mik5=
// File(/data/room/sbf/jusuo.c) of sbf's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是实验室主人龙八休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "龙八");
        set("room_name", "实验室");
        set("room_id", "lab");
        set("room_owner_id", "sbf");
        set("room_position", "碎石小道");
}
