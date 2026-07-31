// SN:TQf8NCD78gNAO]h:
// File(/data/room/ppbrother/jusuo.c) of ppbrother's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是倚王府主人倚碧鸳休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "倚碧鸳");
        set("room_name", "倚王府");
        set("room_id", "ywf");
        set("room_owner_id", "ppbrother");
        set("room_position", "碎石小道");
}
