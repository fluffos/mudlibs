// SN:h`hZGT`4:H65WGk7
// File(/data/room/modao/jusuo.c) of modao's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是瑟思堡主人魔盗休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "魔盗");
        set("room_name", "瑟思堡");
        set("room_id", "roome");
        set("room_owner_id", "modao");
        set("room_position", "碎石小道");
}
