// SN:0nZ3O_WY_DQTBnIn
// File(/data/room/yaoyue/dating.c) of yaoyue's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "移花宫大厅");
	set ("long", @LONG
这就是移花宫主人邀月迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人邀月的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "邀月");
        set("room_name", "移花宫");
        set("room_id", "yhg");
        set("room_owner_id", "yaoyue");
        set("room_position", "碎石小道");
}
