// SN:`]73WGhDbmma7F@f
// File(/data/room/wintel/dating.c) of wintel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "藏娇金屋大厅");
	set ("long", @LONG
这就是藏娇金屋主人天悟迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人天悟的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "天悟");
        set("room_name", "藏娇金屋");
        set("room_id", "jingwu");
        set("room_owner_id", "wintel");
        set("room_position", "青石官道");
}
