// File(/data/room/luoyuna/jusuo.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set("long", "这就是小白居主人大白休息、读书的地方。楼上就是主人的卧室，
西面则是书房。
");

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
    
        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
