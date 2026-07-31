// SN:Ihc5ITUka8K`CiAQ
// File(/data/room/cmlcml/dating.c) of cmlcml's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "逍遥居大厅");
	set ("long", @LONG
这就是逍遥居主人陈林迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人陈林的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "陈林");
        set("room_name", "逍遥居");
        set("room_id", "xyao");
        set("room_owner_id", "cmlcml");
        set("room_position", "碎石小道");
}
