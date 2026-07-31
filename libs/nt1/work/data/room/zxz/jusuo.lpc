// SN:bEO@JA=GV895Nemc
// File(/data/room/zxz/jusuo.c) of zxz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是明霖主人无盐休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "无盐");
        set("room_name", "明霖");
        set("room_id", "roomofzxz");
        set("room_owner_id", "zxz");
        set("room_position", "三岔口");
}
