// SN:U71G\hTmhg?ig9=n
// File(/data/room/xiaosa/dating.c) of xiaosa's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "潇洒大厅");
	set ("long", @LONG
这就是潇洒主人小撒迎送客人的地方。正中有些桌椅，侧面是两
扇屏风。东首是主人小撒的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "小撒");
        set("room_name", "潇洒");
        set("room_id", "xiaosa");
        set("room_owner_id", "xiaosa");
        set("room_position", "名人堂");
}
