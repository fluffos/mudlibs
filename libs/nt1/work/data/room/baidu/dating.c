// SN:FAn]Q\bo@PlXJm6b
// File(/data/room/baidu/dating.c) of baidu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "地狱天堂大厅");
	set ("long", @LONG
这就是地狱天堂主人魔渡众生迎送客人的地方。正中有些桌椅，
侧面是两扇屏风。东首是主人魔渡众生的房间，有一扇木门虚掩着。
南边是大门，出去就是院子。 
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
    
        set("room_owner", "魔渡众生");
        set("room_name", "地狱天堂");
        set("room_id", "baidu");
        set("room_owner_id", "baidu");
        set("room_position", "碎石小道");
}
