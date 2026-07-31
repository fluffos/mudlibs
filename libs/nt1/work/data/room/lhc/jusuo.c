// SN:@DG`naIC0Y\6V]dJ
// File(/data/room/lhc/jusuo.c) of lhc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是大钱库主人灵狐宠休息、读书的地方。楼上就是主人的卧
室，西面则是书房。 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "灵狐宠");
        set("room_name", "大钱库");
        set("room_id", "bankchina");
        set("room_owner_id", "lhc");
        set("room_position", "青砖路");
}
