// SN:LM1TVj6SFD?Vg\7:
// File(/data/room/xtt/jusuo.c) of xtt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是谭谭居主人小谭谭休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "小谭谭");
        set("room_name", "谭谭居");
        set("room_id", "xtt");
        set("room_owner_id", "xtt");
        set("room_position", "树林");
}
