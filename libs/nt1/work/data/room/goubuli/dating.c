// SN:V_mPcTA^KUYj`L3l
// File(/data/room/goubuli/dating.c) of goubuli's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "包子铺大厅");
	set ("long", @LONG
这就是包子铺主人苟不离迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人苟不离的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "苟不离");
        set("room_name", "包子铺");
        set("room_id", "goubuli");
        set("room_owner_id", "goubuli");
        set("room_position", "碎石小道");
}
