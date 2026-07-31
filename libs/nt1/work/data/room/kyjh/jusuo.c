// SN:;@0la2_F7>4o7k0l
// File(/data/room/kyjh/jusuo.c) of kyjh's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是爱巢主人快意江湖休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "快意江湖");
        set("room_name", "爱巢");
        set("room_id", "home");
        set("room_owner_id", "kyjh");
        set("room_position", "三岔口");
}
