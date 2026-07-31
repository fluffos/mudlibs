// SN:;kF8KP]KB9mDdj7d
// File(/data/room/dzgc/dating.c) of dzgc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "锻造厂大厅");
	set ("long", @LONG
这就是锻造厂主人段造厂迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人段造厂的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "段造厂");
        set("room_name", "锻造厂");
        set("room_id", "fac");
        set("room_owner_id", "dzgc");
        set("room_position", "三岔口");
}
