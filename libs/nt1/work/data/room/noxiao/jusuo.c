// SN:`\gU13?Qel:Z46De
// File(/data/room/noxiao/jusuo.c) of noxiao's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是红尘居主人渡无休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "渡无");
        set("room_name", "红尘居");
        set("room_id", "bluesky");
        set("room_owner_id", "noxiao");
        set("room_position", "南海之滨");
}
