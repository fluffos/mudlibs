// SN:ngTCok`CmfbW5f:3
// File(/data/room/abc/jusuo.c) of abc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是农业银行金库主人农业银行休息、读书的地方。楼上就是
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
    
        set("room_owner", "农业银行");
        set("room_name", "农业银行金库");
        set("room_id", "abc");
        set("room_owner_id", "abc");
        set("room_position", "碎石小道");
}
