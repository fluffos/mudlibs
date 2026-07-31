// SN:FE^Z\bYlJ1O3X7KP
// File(/data/room/maker/dating.c) of maker's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药王庄大厅");
	set ("long", @LONG
这就是药王庄主人梅乾迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人梅乾的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "梅乾");
        set("room_name", "药王庄");
        set("room_id", "maker");
        set("room_owner_id", "maker");
        set("room_position", "碎石小道");
}
