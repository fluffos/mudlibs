// SN:Km3K=a\A4V`fme?1
// File(/data/room/dandan/dating.c) of dandan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "米丹米居大厅");
	set ("long", @LONG
这就是米丹米居主人米丹米迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人米丹米的房间，有一扇木门虚掩着。南边
是大门，出去就是院子。 
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
    
        set("room_owner", "米丹米");
        set("room_name", "米丹米居");
        set("room_id", "dandan");
        set("room_owner_id", "dandan");
        set("room_position", "碎石小道");
}
