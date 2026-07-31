// SN:9EG1gbG24^fc\:PP
// File(/data/room/bbwo/dating.c) of bbwo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风雨大厅");
	set ("long", @LONG
这就是风雨主人小波迎送客人的地方。正中有些桌椅，侧面是两
扇屏风。东首是主人小波的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "小波");
        set("room_name", "风雨");
        set("room_id", "bbwo");
        set("room_owner_id", "bbwo");
        set("room_position", "碎石小道");
}
