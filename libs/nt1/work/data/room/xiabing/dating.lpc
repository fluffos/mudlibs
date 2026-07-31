// SN:8j84oSFailcj`hB?
// File(/data/room/xiabing/dating.c) of xiabing's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "惊霸大厅");
	set ("long", @LONG
这就是惊霸主人夏天的冰迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人夏天的冰的房间，有一扇木门虚掩着。南边
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
    
        set("room_owner", "夏天的冰");
        set("room_name", "惊霸");
        set("room_id", "jing");
        set("room_owner_id", "xiabing");
        set("room_position", "青砖路");
}
