// SN:5j6VPVVUMA2^bbFk
// File(/data/room/chinapk/chashi.c) of chinapk's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "茶室");
	set ("long", @LONG
[1;31m茶水间[2;37;0m
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

        set("room_owner", "肯德基");
        set("room_name", "肯德鸡");
        set("room_id", "chinapk");
        set("room_owner_id", "chinapk");
        set("room_position", "树林");
}
