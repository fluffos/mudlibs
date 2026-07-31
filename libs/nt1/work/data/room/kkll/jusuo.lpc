// SN:D3e81Q?2]:XON;KT
// File(/data/room/kkll/jusuo.c) of kkll's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是宿舍主人龙七休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "龙七");
        set("room_name", "宿舍");
        set("room_id", "kkll");
        set("room_owner_id", "kkll");
        set("room_position", "碎石小道");
}
