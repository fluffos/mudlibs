// SN:dEa7_HWW7O>dK3<4
// File(/data/room/ryy/dating.c) of ryy's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "盈盈居大厅");
	set ("long", @LONG
这就是盈盈居主人任盈盈迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人任盈盈的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "任盈盈");
        set("room_name", "盈盈居");
        set("room_id", "ryy");
        set("room_owner_id", "ryy");
        set("room_position", "碎石小道");
}
