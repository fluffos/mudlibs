// SN:oL_4IWE8UPKJRk70
// File(/data/room/she/dating.c) of she's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "思若居大厅");
	set ("long", @LONG
这就是思若居主人黄若思迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人黄若思的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "黄若思");
        set("room_name", "思若居");
        set("room_id", "she");
        set("room_owner_id", "she");
        set("room_position", "碎石小道");
}
