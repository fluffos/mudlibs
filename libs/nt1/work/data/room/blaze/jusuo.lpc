// SN:TO]P99EDSffg=BQ8
// File(/data/room/blaze/jusuo.c) of blaze's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是小雨主人剑雨休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "剑雨");
        set("room_name", "小雨");
        set("room_id", "rain");
        set("room_owner_id", "blaze");
        set("room_position", "青砖路");
}
