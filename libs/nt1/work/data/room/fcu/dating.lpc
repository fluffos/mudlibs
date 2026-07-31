// SN:o_34RJ<]_gDCE:>F
// File(/data/room/fcu/dating.c) of fcu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药店大厅");
	set ("long", @LONG
这就是药店主人龙九迎送客人的地方。正中有些桌椅，侧面是两
扇屏风。东首是主人龙九的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "龙九");
        set("room_name", "药店");
        set("room_id", "fcu");
        set("room_owner_id", "fcu");
        set("room_position", "碎石小道");
}
