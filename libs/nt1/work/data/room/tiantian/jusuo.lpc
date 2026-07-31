// SN:G`BfR4TIe5dT6Ee^
// File(/data/room/tiantian/jusuo.c) of tiantian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是猪猪会总坛主人猪猪快跑休息、读书的地方。楼上就是主
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
    
        set("room_owner", "猪猪快跑");
        set("room_name", "猪猪会总坛");
        set("room_id", "tian");
        set("room_owner_id", "tiantian");
        set("room_position", "南大街");
}
