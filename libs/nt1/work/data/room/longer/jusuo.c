// SN:4TfU0mkZ5c:cioQH
// File(/data/room/longer/jusuo.c) of longer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是药王山庄主人药王休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "药王");
        set("room_name", "药王山庄");
        set("room_id", "longroom");
        set("room_owner_id", "longer");
        set("room_position", "山路");
}
