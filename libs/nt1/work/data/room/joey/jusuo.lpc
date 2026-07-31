// SN:`]13VM56_BTO[m@T
// File(/data/room/joey/jusuo.c) of joey's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是不想回家主人容祖儿休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "容祖儿");
        set("room_name", "不想回家");
        set("room_id", "bxhj");
        set("room_owner_id", "joey");
        set("room_position", "三岔口");
}
