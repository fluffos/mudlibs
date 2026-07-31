// SN:kHk5DI7oZ0mgO?H8
// File(/data/room/habo/dating.c) of habo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "韩大少家大厅");
	set ("long", @LONG
这就是韩大少家主人韩博迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人韩博的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "韩博");
        set("room_name", "韩大少家");
        set("room_id", "tohabo");
        set("room_owner_id", "habo");
        set("room_position", "三岔口");
}
