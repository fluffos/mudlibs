// SN:O^IHR2GbM9Gkc`G8
// File(/data/room/mausoleum/dating.c) of mausoleum's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "陵墓大厅");
	set ("long", @LONG
这就是陵墓主人唐昭陵迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人唐昭陵的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "唐昭陵");
        set("room_name", "陵墓");
        set("room_id", "grave");
        set("room_owner_id", "mausoleum");
        set("room_position", "碎石小道");
}
