// SN:0]IOAHib`gmZGI^Q
// File(/data/room/kikyou/jusuo.c) of kikyou's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是花之语主人桔梗休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "桔梗");
        set("room_name", "花之语");
        set("room_id", "kikyou");
        set("room_owner_id", "kikyou");
        set("room_position", "碎石小道");
}
