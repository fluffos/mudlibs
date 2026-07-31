// SN:>a1<>oIhO>3@HEg;
// File(/data/room/rainie/dating.c) of rainie's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "慈航静斋大厅");
	set ("long", @LONG
这就是慈航静斋主人秦梦遥迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人秦梦遥的房间，有一扇木门虚掩着。南边
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
    
        set("room_owner", "秦梦遥");
        set("room_name", "慈航静斋");
        set("room_id", "mengyao");
        set("room_owner_id", "rainie");
        set("room_position", "三岔口");
}
