// SN:GH43_P6Y<QHo?fo_
// File(/data/room/duzhi/dating.c) of duzhi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "白虎殿大厅");
	set ("long", @LONG
这就是白虎殿主人毒指迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人毒指的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "毒指");
        set("room_name", "白虎殿");
        set("room_id", "bhd");
        set("room_owner_id", "duzhi");
        set("room_position", "碎石小道");
}
