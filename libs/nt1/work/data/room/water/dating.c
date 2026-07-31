// SN:k3L::1iJAN9if4eZ
// File(/data/room/water/dating.c) of water's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水之间大厅");
	set ("long", @LONG
这就是水之间主人水无痕迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人水无痕的房间，有一扇木门虚掩着。南边是
大门，出去就是院子。 
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
    
        set("room_owner", "水无痕");
        set("room_name", "水之间");
        set("room_id", "water");
        set("room_owner_id", "water");
        set("room_position", "碎石小道");
}
