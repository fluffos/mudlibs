// SN:P2d3:>YfD[bolJEZ
// File(/data/room/best/jusuo.c) of best's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是萍萍的屋主人黄萍萍休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "黄萍萍");
        set("room_name", "萍萍的屋");
        set("room_id", "best");
        set("room_owner_id", "best");
        set("room_position", "山路");
}
