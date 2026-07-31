// SN:GCgNM5^eP=O0C3Lm
// File(/data/room/deadyour/chashi.c) of deadyour's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "茶室");
	set ("long", @LONG
是一个玲珑小巧的茶室，很是显得精致。正中有一茶几，两旁立
着两个妙龄少女，正在听候主人的吩咐(tea)。 
LONG );

	set("exits", ([
		"west"  : __DIR__"yingke",
	]));

        set("objects", ([
                "/d/room/roomnpc/teagirl" : 2,
        ]));

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "西红柿");
        set("room_name", "凤巢");
        set("room_id", "deadyour");
        set("room_owner_id", "deadyour");
        set("room_position", "碎石小道");
}
