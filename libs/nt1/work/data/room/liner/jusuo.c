// SN:GAh_E7S`4A3F]>nL
// File(/data/room/liner/jusuo.c) of liner's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是梦幻乐园主人胡玲儿休息、读书的地方。楼上就是主人的
卧室，西面则是书房。 
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
    
        set("room_owner", "胡玲儿");
        set("room_name", "梦幻乐园");
        set("room_id", "liner");
        set("room_owner_id", "liner");
        set("room_position", "碎石小道");
}
