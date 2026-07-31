// SN:RAU90iR0;XGU8aTm
// File(/data/room/boa/dating.c) of boa's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天堂乐土大厅");
	set ("long", @LONG
这就是天堂乐土主人宝儿迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人宝儿的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "宝儿");
        set("room_name", "天堂乐土");
        set("room_id", "elysium");
        set("room_owner_id", "boa");
        set("room_position", "南大街");
}
