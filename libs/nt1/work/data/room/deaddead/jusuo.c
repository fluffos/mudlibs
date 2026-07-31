// SN:GRRlRmcTBS97`PaD
// File(/data/room/deaddead/jusuo.c) of deaddead's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是游乐场主人哈后来休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "哈后来");
        set("room_name", "游乐场");
        set("room_id", "deaddead");
        set("room_owner_id", "deaddead");
        set("room_position", "碎石小道");
}
