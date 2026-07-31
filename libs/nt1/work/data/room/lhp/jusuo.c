// SN:C4fFT8ONR6JUCfSV
// File(/data/room/lhp/jusuo.c) of lhp's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是冰风溪谷主人少龙休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "少龙");
        set("room_name", "冰风溪谷");
        set("room_id", "ice");
        set("room_owner_id", "lhp");
        set("room_position", "树林");
}
