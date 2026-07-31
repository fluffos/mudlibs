// SN:fVj]o4I`=]ac0\[`
// File(/data/room/lovet/jusuo.c) of lovet's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是飘飘亭主人执着休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "执着");
        set("room_name", "飘飘亭");
        set("room_id", "loveting");
        set("room_owner_id", "lovet");
        set("room_position", "名人堂");
}
