// SN:cQMEVRMF`A^04lj2
// File(/data/room/bafenghan/dating.c) of bafenghan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "突厥帐篷大厅");
	set ("long", @LONG
这就是突厥帐篷主人跋锋寒迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人跋锋寒的房间，有一扇木门虚掩着。南边
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
    
        set("room_owner", "跋锋寒");
        set("room_name", "突厥帐篷");
        set("room_id", "bafenghan");
        set("room_owner_id", "bafenghan");
        set("room_position", "碎石小道");
}
