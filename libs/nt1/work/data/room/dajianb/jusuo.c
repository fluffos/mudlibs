// SN:`BPP11>\P1=l^9GG
// File(/data/room/dajianb/jusuo.c) of dajianb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是风之居主人风二中休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "风二中");
        set("room_name", "风之居");
        set("room_id", "wind");
        set("room_owner_id", "dajianb");
        set("room_position", "山路");
}
