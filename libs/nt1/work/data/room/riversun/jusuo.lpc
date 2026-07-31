// SN:kOQ`1B9g^heb81m@
// File(/data/room/riversun/jusuo.c) of riversun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是雅阁主人段小强休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "段小强");
        set("room_name", "雅阁");
        set("room_id", "riversun");
        set("room_owner_id", "riversun");
        set("room_position", "青砖路");
}
