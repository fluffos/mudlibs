// SN:bij=KIS?iaK=floQ
// File(/data/room/gold/dating.c) of gold's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "黄金岛大厅");
	set ("long", @LONG
这就是黄金岛主人蓝魔迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人蓝魔的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "蓝魔");
        set("room_name", "黄金岛");
        set("room_id", "gold");
        set("room_owner_id", "gold");
        set("room_position", "碎石小道");
}
