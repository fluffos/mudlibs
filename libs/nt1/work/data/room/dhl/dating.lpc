// SN:45lmN_9QOd5GiJeT
// File(/data/room/dhl/dating.c) of dhl's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "温顺小屋大厅");
	set ("long", @LONG
这就是温顺小屋主人啊勇迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人啊勇的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "啊勇");
        set("room_name", "温顺小屋");
        set("room_id", "dhl");
        set("room_owner_id", "dhl");
        set("room_position", "碎石小道");
}
