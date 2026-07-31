// SN:<ni_ZG8RNSkW^KHL
// File(/data/room/workera/dating.c) of workera's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "泥潭丹药二大厅");
	set ("long", @LONG
这就是泥潭丹药二主人炼丹工人迎送客人的地方。正中有些桌椅，
侧面是两扇屏风。东首是主人炼丹工人的房间，有一扇木门虚掩着。
南边是大门，出去就是院子。 
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
    
        set("room_owner", "炼丹工人");
        set("room_name", "泥潭丹药二");
        set("room_id", "ntdy");
        set("room_owner_id", "workera");
        set("room_position", "碎石小道");
}
