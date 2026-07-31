// SN:g<EhJUPbV`VPFI2V
// File(/data/room/tan/jusuo.c) of tan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是似水年华主人明柳休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "明柳");
        set("room_name", "似水年华");
        set("room_id", "times");
        set("room_owner_id", "tan");
        set("room_position", "山洪瀑布");
}
