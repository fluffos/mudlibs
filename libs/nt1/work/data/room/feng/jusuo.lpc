// SN:RZPTe:KJW@MHX_FX
// File(/data/room/feng/jusuo.c) of feng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是听风阁主人青衣修罗休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "青衣修罗");
        set("room_name", "听风阁");
        set("room_id", "feng");
        set("room_owner_id", "feng");
        set("room_position", "三岔口");
}
