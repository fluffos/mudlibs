// SN:L8Henm_?<QUP42Z<
// File(/data/room/kanera/jusuo.c) of kanera's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是米虫的窝主人米虫休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "米虫");
        set("room_name", "米虫的窝");
        set("room_id", "kanera");
        set("room_owner_id", "kanera");
        set("room_position", "碎石小道");
}
