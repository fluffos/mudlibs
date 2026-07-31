// SN:ALHBDMV@i`5VlFG9
// File(/data/room/death/jusuo.c) of death's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是亡灵神殿主人死神休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "死神");
        set("room_name", "亡灵神殿");
        set("room_id", "die");
        set("room_owner_id", "death");
        set("room_position", "碎石小道");
}
