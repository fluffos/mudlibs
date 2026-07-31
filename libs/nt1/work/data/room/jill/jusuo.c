// SN:EG>:cfmHUnWQ5@D:
// File(/data/room/jill/jusuo.c) of jill's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是一号房主人徐婕儿休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "徐婕儿");
        set("room_name", "一号房");
        set("room_id", "one");
        set("room_owner_id", "jill");
        set("room_position", "青砖路");
}
