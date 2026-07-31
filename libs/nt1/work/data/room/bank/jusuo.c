// SN:hk:khk`4I9AkVI;a
// File(/data/room/bank/jusuo.c) of bank's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是中国银行金库主人中国银行休息、读书的地方。楼上就是
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
    
        set("room_owner", "中国银行");
        set("room_name", "中国银行金库");
        set("room_id", "bank");
        set("room_owner_id", "bank");
        set("room_position", "碎石小道");
}
