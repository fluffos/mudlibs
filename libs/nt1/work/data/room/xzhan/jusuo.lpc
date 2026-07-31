// SN:nGHXA6556c_5k_\^
// File(/data/room/xzhan/jusuo.c) of xzhan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是血池山庄主人血战休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "血战");
        set("room_name", "血池山庄");
        set("room_id", "xuechi");
        set("room_owner_id", "xzhan");
        set("room_position", "碎石小道");
}
