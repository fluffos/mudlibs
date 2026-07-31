// SN:W4j4k:fJL8M38TPo
// File(/data/room/heart/jusuo.c) of heart's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是琉璃香榭主人舞莲休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "舞莲");
        set("room_name", "琉璃香榭");
        set("room_id", "heart");
        set("room_owner_id", "heart");
        set("room_position", "树林");
}
