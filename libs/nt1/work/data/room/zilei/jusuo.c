// SN:CP7Z7[gSQ8Gn`12R
// File(/data/room/zilei/jusuo.c) of zilei's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是思念居主人紫雷休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "紫雷");
        set("room_name", "思念居");
        set("room_id", "sinian");
        set("room_owner_id", "zilei");
        set("room_position", "名人堂");
}
