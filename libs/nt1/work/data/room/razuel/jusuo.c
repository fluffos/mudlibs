// SN:RU?HO`X;GoT2n?8d
// File(/data/room/razuel/jusuo.c) of razuel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天使地狱主人澄瑞休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "澄瑞");
        set("room_name", "天使地狱");
        set("room_id", "losangels");
        set("room_owner_id", "razuel");
        set("room_position", "青砖路");
}
