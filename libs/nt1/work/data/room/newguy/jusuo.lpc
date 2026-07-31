// SN:b0=:777U21^U7@h^
// File(/data/room/newguy/jusuo.c) of newguy's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是小房子主人飞人休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "飞人");
        set("room_name", "小房子");
        set("room_id", "king");
        set("room_owner_id", "newguy");
        set("room_position", "碎石小道");
}
