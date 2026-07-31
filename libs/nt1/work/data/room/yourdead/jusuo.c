// SN:CKWNlogbd?m6bI11
// File(/data/room/yourdead/jusuo.c) of yourdead's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是龙潭主人渡会休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "渡会");
        set("room_name", "龙潭");
        set("room_id", "yourdead");
        set("room_owner_id", "yourdead");
        set("room_position", "碎石小道");
}
