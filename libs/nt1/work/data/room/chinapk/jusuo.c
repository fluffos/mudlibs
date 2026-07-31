// SN:m1\T[VUh]iN:hmdI
// File(/data/room/chinapk/jusuo.c) of chinapk's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是肯德鸡主人肯德基休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "肯德基");
        set("room_name", "肯德鸡");
        set("room_id", "chinapk");
        set("room_owner_id", "chinapk");
        set("room_position", "树林");
}
