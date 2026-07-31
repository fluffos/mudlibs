// SN:@DOM2^oD?>Xgm<:_
// File(/data/room/tiger/dating.c) of tiger's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "虎之爪大厅");
	set ("long", @LONG
这就是虎之爪主人白虎迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人白虎的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "白虎");
        set("room_name", "虎之爪");
        set("room_id", "tiger");
        set("room_owner_id", "tiger");
        set("room_position", "碎石小道");
}
