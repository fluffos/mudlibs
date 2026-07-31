// SN:83lAnl^L;]o5?G^F
// File(/data/room/shuiwh/dating.c) of shuiwh's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "玉清宫大厅");
	set ("long", @LONG
这就是玉清宫主人水无恨迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人水无恨的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "水无恨");
        set("room_name", "玉清宫");
        set("room_id", "shuiwh");
        set("room_owner_id", "shuiwh");
        set("room_position", "碎石小道");
}
