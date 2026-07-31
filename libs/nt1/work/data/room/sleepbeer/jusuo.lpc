// SN:acGS1D:jH>n9@DE3
// File(/data/room/sleepbeer/jusuo.c) of sleepbeer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是猪笼主人紫萱休息、读书的地方。楼上就是主人的卧室，
西面则是书房。 
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
    
        set("room_owner", "紫萱");
        set("room_name", "猪笼");
        set("room_id", "sexgirl");
        set("room_owner_id", "sleepbeer");
        set("room_position", "碎石小道");
}
