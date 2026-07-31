// SN:ilEcCn6mfg3D5kec
// File(/data/room/funlove/jusuo.c) of funlove's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天与地主人爱玩笑休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "爱玩笑");
        set("room_name", "天与地");
        set("room_id", "funlove");
        set("room_owner_id", "funlove");
        set("room_position", "碎石小道");
}
