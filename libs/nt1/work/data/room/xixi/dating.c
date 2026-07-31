// SN:jd>Z9^icV3o[a3^6
// File(/data/room/xixi/dating.c) of xixi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "嘻嘻哈哈俯大厅");
	set ("long", @LONG
这就是嘻嘻哈哈俯主人嘻嘻迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人嘻嘻的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "嘻嘻");
        set("room_name", "嘻嘻哈哈俯");
        set("room_id", "xixihaha");
        set("room_owner_id", "xixi");
        set("room_position", "三岔口");
}
