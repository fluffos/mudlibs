// SN:@P4i=5DEW;43J0C_
// File(/data/room/godkenny/jusuo.c) of godkenny's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是糖果点心屋主人云飘之翼休息、读书的地方。楼上就是主
人的卧室，西面则是书房。 
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
    
        set("room_owner", "云飘之翼");
        set("room_name", "糖果点心屋");
        set("room_id", "candy");
        set("room_owner_id", "godkenny");
        set("room_position", "青石官道");
}
