// SN:>^?mTRZWOn:eTa\8
// File(/data/room/stefyanzi/jusuo.c) of stefyanzi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是听雨轩主人夜听雨休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "夜听雨");
        set("room_name", "听雨轩");
        set("room_id", "stefyanzi");
        set("room_owner_id", "stefyanzi");
        set("room_position", "碎石小道");
}
