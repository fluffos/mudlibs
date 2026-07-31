// SN:nG5>DG]4YacaH6bg
// File(/data/room/lonely/jusuo.c) of lonely's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是高处不胜寒主人高处不胜寒休息、读书的地方。楼上就是
主人的卧室，西面则是书房。 
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
    
        set("room_owner", "高处不胜寒");
        set("room_name", "高处不胜寒");
        set("room_id", "lonely");
        set("room_owner_id", "lonely");
        set("room_position", "名人堂");
}
