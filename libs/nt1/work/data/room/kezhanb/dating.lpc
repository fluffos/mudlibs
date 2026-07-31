// SN:h\i@h2LE]MoR;[_\
// File(/data/room/kezhanb/dating.c) of kezhanb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "龙门客栈大厅");
	set ("long", @LONG
这就是龙门客栈主人龙门客栈迎送客人的地方。正中有些桌椅，
侧面是两扇屏风。东首是主人龙门客栈的房间，有一扇木门虚掩着。
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
    
        set("room_owner", "龙门客栈");
        set("room_name", "龙门客栈");
        set("room_id", "kezhanb");
        set("room_owner_id", "kezhanb");
        set("room_position", "名人堂");
}
