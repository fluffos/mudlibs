// SN:2lf>2:=HOj;GC`5=
// File(/data/room/newerb/jusuo.c) of newerb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是名字难取主人名字难取休息、读书的地方。楼上就是主人
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
    
        set("room_owner", "名字难取");
        set("room_name", "名字难取");
        set("room_id", "newera");
        set("room_owner_id", "newerb");
        set("room_position", "碎石小道");
}
