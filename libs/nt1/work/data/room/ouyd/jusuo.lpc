// SN:FTU3lQF9Z@XkidGK
// File(/data/room/ouyd/jusuo.c) of ouyd's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是白驼山庄主人欧阳毒休息、读书的地方。楼上就是主人的
卧室，西面则是书房。 
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
    
        set("room_owner", "欧阳毒");
        set("room_name", "白驼山庄");
        set("room_id", "ouyd");
        set("room_owner_id", "ouyd");
        set("room_position", "碎石小道");
}
