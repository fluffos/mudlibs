// SN:QkjR2N:N]@jInDWQ
// File(/data/room/lastlord/jusuo.c) of lastlord's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是乞丐窝主人摩诃流星休息、读书的地方。楼上就是主人的
卧室，西面则是书房。 
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
    
        set("room_owner", "摩诃流星");
        set("room_name", "乞丐窝");
        set("room_id", "lord");
        set("room_owner_id", "lastlord");
        set("room_position", "树林");
}
