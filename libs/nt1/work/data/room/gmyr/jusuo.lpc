// SN:B492XBf3LccA?l;k
// File(/data/room/gmyr/jusuo.c) of gmyr's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是流浪居主人伊人古墓休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "伊人古墓");
        set("room_name", "流浪居");
        set("room_id", "gmyr");
        set("room_owner_id", "gmyr");
        set("room_position", "三岔口");
}
