// SN:<h485XW01`kl>>Zk
// File(/data/room/ouyangsiu/dating.c) of ouyangsiu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "醉翁居大厅");
	set ("long", @LONG
这就是醉翁居主人欧阳修迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人欧阳修的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "欧阳修");
        set("room_name", "醉翁居");
        set("room_id", "ouyang");
        set("room_owner_id", "ouyangsiu");
        set("room_position", "碎石小道");
}
