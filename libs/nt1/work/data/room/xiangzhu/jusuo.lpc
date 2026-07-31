// SN:9XkdYi=52m]IN<Km
// File(/data/room/xiangzhu/jusuo.c) of xiangzhu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是湘妃宫主人湘竹休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "湘竹");
        set("room_name", "湘妃宫");
        set("room_id", "xiangfei");
        set("room_owner_id", "xiangzhu");
        set("room_position", "碎石小道");
}
