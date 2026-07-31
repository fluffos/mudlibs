// SN:e0J^8;V02go\Qo\U
// File(/data/room/wiz/jusuo.c) of wiz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天宫主人巫师休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "巫师");
        set("room_name", "天宫");
        set("room_id", "roomc");
        set("room_owner_id", "wiz");
        set("room_position", "碎石小道");
}
