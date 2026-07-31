// SN:[BJ6PA9A^LB_Da6L
// File(/data/room/sau/jusuo.c) of sau's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是浪云吧主人白云休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "白云");
        set("room_name", "浪云吧");
        set("room_id", "sau");
        set("room_owner_id", "sau");
        set("room_position", "碎石小道");
}
