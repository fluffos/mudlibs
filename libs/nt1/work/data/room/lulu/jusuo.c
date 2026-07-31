// SN:RR=\IOANiWGIbYlc
// File(/data/room/lulu/jusuo.c) of lulu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是神剑山庄主人唐绣休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "唐绣");
        set("room_name", "神剑山庄");
        set("room_id", "lulu");
        set("room_owner_id", "lulu");
        set("room_position", "碎石小道");
}
