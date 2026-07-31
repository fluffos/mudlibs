// SN:1fB2=Nf?K_5ccHe\
// File(/data/room/vampire/jusuo.c) of vampire's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是古堡主人将臣休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "将臣");
        set("room_name", "古堡");
        set("room_id", "castle");
        set("room_owner_id", "vampire");
        set("room_position", "三岔口");
}
