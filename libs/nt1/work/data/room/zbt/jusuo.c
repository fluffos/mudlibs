// SN:O>e]g>;O`MWM;M`^
// File(/data/room/zbt/jusuo.c) of zbt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是大宅门主人清咒休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "清咒");
        set("room_name", "大宅门");
        set("room_id", "zbt");
        set("room_owner_id", "zbt");
        set("room_position", "名人堂");
}
