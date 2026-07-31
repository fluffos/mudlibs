// SN:^TmB;[ZO9MPFOchC
// File(/data/room/canlv/dating.c) of canlv's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "无魂居大厅");
	set ("long", @LONG
这就是无魂居主人残旅迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人残旅的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "残旅");
        set("room_name", "无魂居");
        set("room_id", "canlv");
        set("room_owner_id", "canlv");
        set("room_position", "碎石小道");
}
