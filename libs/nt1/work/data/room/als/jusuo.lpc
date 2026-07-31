// SN:F8ei^nB;6XJ7D04G
// File(/data/room/als/jusuo.c) of als's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是海德酒店主人灌汤包子休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
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
    
        set("room_owner", "灌汤包子");
        set("room_name", "海德酒店");
        set("room_id", "hotl");
        set("room_owner_id", "als");
        set("room_position", "名人堂");
}
