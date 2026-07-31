// SN:W6;:2;T@0nm<;\kE
// File(/data/room/tanghua/dating.c) of tanghua's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "花满楼大厅");
	set ("long", @LONG
这就是花满楼主人唐花迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人唐花的房间，有一扇木门虚掩着。南边是大门，
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
    
        set("room_owner", "唐花");
        set("room_name", "花满楼");
        set("room_id", "hua");
        set("room_owner_id", "tanghua");
        set("room_position", "名人堂");
}
