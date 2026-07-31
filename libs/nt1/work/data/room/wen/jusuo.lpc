// SN:kBb;8IZm@`^h5B3G
// File(/data/room/wen/jusuo.c) of wen's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是听雨轩主人叶落听风休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "叶落听风");
        set("room_name", "听雨轩");
        set("room_id", "wen");
        set("room_owner_id", "wen");
        set("room_position", "三岔口");
}
