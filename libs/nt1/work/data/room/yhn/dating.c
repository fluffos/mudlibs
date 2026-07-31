// SN:2F3CIho::;MN6bb2
// File(/data/room/yhn/dating.c) of yhn's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "高丽山庄大厅");
	set ("long", @LONG
这就是高丽山庄主人傅君迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人傅君的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "傅君");
        set("room_name", "高丽山庄");
        set("room_id", "yhn");
        set("room_owner_id", "yhn");
        set("room_position", "碎石小道");
}
