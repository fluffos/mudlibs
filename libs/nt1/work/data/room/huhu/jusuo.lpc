// SN:3cVEISo>cedMmVo5
// File(/data/room/huhu/jusuo.c) of huhu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是关外小屋主人胡归真休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "胡归真");
        set("room_name", "关外小屋");
        set("room_id", "huhu");
        set("room_owner_id", "huhu");
        set("room_position", "碎石小道");
}
