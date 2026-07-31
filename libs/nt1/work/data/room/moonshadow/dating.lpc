// SN:]3c^Qjoihe=T_;5X
// File(/data/room/moonshadow/dating.c) of moonshadow's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "月梦宫大厅");
	set ("long", @LONG
这就是月梦宫主人月影迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人月影的房间，有一扇木门虚掩着。南边是大门，
出去就是院子。 
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
    
        set("room_owner", "月影");
        set("room_name", "月梦宫");
        set("room_id", "yuemeng");
        set("room_owner_id", "moonshadow");
        set("room_position", "青砖路");
}
