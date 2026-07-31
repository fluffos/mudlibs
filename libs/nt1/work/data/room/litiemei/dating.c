// SN:MB8j@nN_jea=GZko
// File(/data/room/litiemei/dating.c) of litiemei's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "逍遥居大厅");
	set ("long", @LONG
这就是逍遥居主人李铁梅迎送客人的地方。正中有些桌椅，侧面
是两扇屏风。东首是主人李铁梅的房间，有一扇木门虚掩着。南边是
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
    
        set("room_owner", "李铁梅");
        set("room_name", "逍遥居");
        set("room_id", "litiemei");
        set("room_owner_id", "litiemei");
        set("room_position", "名人堂");
}
