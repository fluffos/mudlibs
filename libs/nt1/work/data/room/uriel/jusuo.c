// SN:Od7mgBEdXOLJAAgo
// File(/data/room/uriel/jusuo.c) of uriel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天堂主人乌里叶休息、读书的地方。楼上就是主人的卧室，
西面则是书房。 
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
    
        set("room_owner", "乌里叶");
        set("room_name", "天堂");
        set("room_id", "heaven");
        set("room_owner_id", "uriel");
        set("room_position", "青砖路");
}
