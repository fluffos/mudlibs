// SN:c9Ca\T1mMV\EQo[4
// File(/data/room/wenc/jusuo.c) of wenc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是欧阳府主人欧阳闻浩休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "欧阳闻浩");
        set("room_name", "欧阳府");
        set("room_id", "wenc");
        set("room_owner_id", "wenc");
        set("room_position", "碎石小道");
}
