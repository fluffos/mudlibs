// SN::LF^U]:8OJ_fMJJI
// File(/data/room/cbc/jusuo.c) of cbc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是建设银行金库主人建设银行休息、读书的地方。楼上就是
主人的卧室，西面则是书房。 
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
    
        set("room_owner", "建设银行");
        set("room_name", "建设银行金库");
        set("room_id", "cbc");
        set("room_owner_id", "cbc");
        set("room_position", "碎石小道");
}
