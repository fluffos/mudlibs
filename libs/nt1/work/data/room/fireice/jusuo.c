// SN:cdN1ic@P?0:`Hd?4
// File(/data/room/fireice/jusuo.c) of fireice's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是云闲居主人水灵休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "水灵");
        set("room_name", "云闲居");
        set("room_id", "king");
        set("room_owner_id", "fireice");
        set("room_position", "树林");
}
