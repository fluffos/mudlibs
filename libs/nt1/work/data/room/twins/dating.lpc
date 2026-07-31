// SN:JUFgM<D8edXMmPf0
// File(/data/room/twins/dating.c) of twins's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "二十三号大厅");
	set ("long", @LONG
这就是二十三号主人吐温迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人吐温的房间，有一扇木门虚掩着。南边是大
门，出去就是院子。 
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "吐温");
        set("room_name", "二十三号");
        set("room_id", "twins");
        set("room_owner_id", "twins");
        set("room_position", "碎石小道");
}
