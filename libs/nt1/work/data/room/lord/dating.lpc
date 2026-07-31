// SN:5`LeEN?:=e<BkKfj
// File(/data/room/lord/dating.c) of lord's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "阿房宫大厅");
	set ("long", @LONG
这就是阿房宫主人赢政迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人赢政的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "赢政");
        set("room_name", "阿房宫");
        set("room_id", "lordpalace");
        set("room_owner_id", "lord");
        set("room_position", "碎石小道");
}
