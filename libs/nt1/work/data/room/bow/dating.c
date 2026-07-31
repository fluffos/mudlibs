// SN:0NNm9A=kVGiFPQ1G
// File(/data/room/bow/dating.c) of bow's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风流剧大厅");
	set ("long", @LONG
这就是风流剧主人风流女人迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人风流女人的房间，有一扇木门虚掩着。南
边是大门，出去就是院子。 
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
    
        set("room_owner", "风流女人");
        set("room_name", "风流剧");
        set("room_id", "bow");
        set("room_owner_id", "bow");
        set("room_position", "碎石小道");
}
