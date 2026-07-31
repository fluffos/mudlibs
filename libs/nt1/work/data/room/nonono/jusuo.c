// SN:ejRc5_ZL8a]0G[k8
// File(/data/room/nonono/jusuo.c) of nonono's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天之亭主人罪不至死休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "罪不至死");
        set("room_name", "天之亭");
        set("room_id", "nonono");
        set("room_owner_id", "nonono");
        set("room_position", "碎石小道");
}
