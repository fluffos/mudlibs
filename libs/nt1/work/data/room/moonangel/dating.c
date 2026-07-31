// SN:?eRN:`]SB5fA5RN8
// File(/data/room/moonangel/dating.c) of moonangel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "太阴殿大厅");
	set ("long", @LONG
这就是太阴殿主人月天使迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人月天使的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "月天使");
        set("room_name", "太阴殿");
        set("room_id", "moon");
        set("room_owner_id", "moonangel");
        set("room_position", "三岔口");
}
