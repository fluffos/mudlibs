// SN:8BSX2O5G^5E>fcjB
// File(/data/room/acmn/jusuo.c) of acmn's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是务实居主人渡无休息、读书的地方。楼上就是主人的卧室，
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
        set("room_name", "务实居");
        set("room_id", "acmn");
        set("room_owner_id", "acmn");
        set("room_position", "碎石小道");
}
