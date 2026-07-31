// SN:fKOl=:nOn_gQMILl
// File(/data/room/tinger/jusuo.c) of tinger's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是黎苑小筑主人婷儿休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "婷儿");
        set("room_name", "黎苑小筑");
        set("room_id", "liyuan");
        set("room_owner_id", "tinger");
        set("room_position", "碎石小道");
}
