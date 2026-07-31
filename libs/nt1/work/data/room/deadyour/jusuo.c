// SN:g@F6K>8lVMnRRaIf
// File(/data/room/deadyour/jusuo.c) of deadyour's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是凤巢主人西红柿休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "西红柿");
        set("room_name", "凤巢");
        set("room_id", "deadyour");
        set("room_owner_id", "deadyour");
        set("room_position", "碎石小道");
}
