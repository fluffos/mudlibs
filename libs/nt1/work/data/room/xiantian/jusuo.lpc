// SN:m0@>AVSRi72Hm]dc
// File(/data/room/xiantian/jusuo.c) of xiantian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是猪猪村中屋主人先天功休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
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
    
        set("room_owner", "先天功");
        set("room_name", "猪猪村中屋");
        set("room_id", "piggyi");
        set("room_owner_id", "xiantian");
        set("room_position", "碎石小道");
}
