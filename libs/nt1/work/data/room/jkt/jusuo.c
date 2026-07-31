// SN:>0U<n=UQa\4;<IYf
// File(/data/room/jkt/jusuo.c) of jkt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是和尚居士主人渡独休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "渡独");
        set("room_name", "和尚居士");
        set("room_id", "shaolin");
        set("room_owner_id", "jkt");
        set("room_position", "碎石小道");
}
