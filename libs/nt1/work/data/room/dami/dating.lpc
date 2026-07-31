// SN:Z;Ul1YfmEENelYO`
// File(/data/room/dami/dating.c) of dami's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "米库大厅");
	set ("long", @LONG
这就是米库主人大米迎送客人的地方。正中有些桌椅，侧面是两
扇屏风。东首是主人大米的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "大米");
        set("room_name", "米库");
        set("room_id", "dami");
        set("room_owner_id", "dami");
        set("room_position", "名人堂");
}
