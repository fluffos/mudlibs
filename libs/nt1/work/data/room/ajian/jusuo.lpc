// SN:FB:gYOI@fioQZjQ5
// File(/data/room/ajian/jusuo.c) of ajian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是龙盘江南主人啊健休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "啊健");
        set("room_name", "龙盘江南");
        set("room_id", "longjn");
        set("room_owner_id", "ajian");
        set("room_position", "山路");
}
