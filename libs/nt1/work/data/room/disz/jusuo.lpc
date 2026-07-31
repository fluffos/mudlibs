// SN:cL40o_VDfk:791Cm
// File(/data/room/disz/jusuo.c) of disz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是第三梯队主人杯子休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "杯子");
        set("room_name", "第三梯队");
        set("room_id", "disz");
        set("room_owner_id", "disz");
        set("room_position", "三岔口");
}
