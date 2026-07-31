// SN:6o2Q][ZUMI;\9>`G
// File(/data/room/xdx/jusuo.c) of xdx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是紫气山庄主人净玄休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "净玄");
        set("room_name", "紫气山庄");
        set("room_id", "starg");
        set("room_owner_id", "xdx");
        set("room_position", "紫气台");
}
