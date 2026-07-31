// SN:JFWAC7[oEE;EeofM
// File(/data/room/wgpj/dating.c) of wgpj's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "刚子的家大厅");
	set ("long", @LONG
这就是刚子的家主人刚子迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人刚子的房间，有一扇木门虚掩着。南边是大
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
    
        set("room_owner", "刚子");
        set("room_name", "刚子的家");
        set("room_id", "wgpjshome");
        set("room_owner_id", "wgpj");
        set("room_position", "三岔口");
}
