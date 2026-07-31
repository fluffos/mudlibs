// SN:S4C@<T0JZ;DB^f>d
// File(/data/room/bad/dating.c) of bad's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "野皇城大厅");
	set ("long", @LONG
这就是野皇城主人坏男孩迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人坏男孩的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "坏男孩");
        set("room_name", "野皇城");
        set("room_id", "bad");
        set("room_owner_id", "bad");
        set("room_position", "名人堂");
}
