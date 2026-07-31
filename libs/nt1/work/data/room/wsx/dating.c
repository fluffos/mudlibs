// SN:Z70E0S32??lHZ2?G
// File(/data/room/wsx/dating.c) of wsx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "学友联盟大厅");
	set ("long", @LONG
这就是学友联盟主人张学友迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人张学友的房间，有一扇木门虚掩着。南边
是大门，出去就是院子。 
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
    
        set("room_owner", "张学友");
        set("room_name", "学友联盟");
        set("room_id", "wsx");
        set("room_owner_id", "wsx");
        set("room_position", "碎石小道");
}
