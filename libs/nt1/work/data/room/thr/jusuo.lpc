// SN:IKXm[54c11lW`4Rg
// File(/data/room/thr/jusuo.c) of thr's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是二班主人阿二休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "阿二");
        set("room_name", "二班");
        set("room_id", "erban");
        set("room_owner_id", "thr");
        set("room_position", "青石官道");
}
