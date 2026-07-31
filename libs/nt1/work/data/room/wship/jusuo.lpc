// SN:dn`5RgUfdKcYV@Qk
// File(/data/room/wship/jusuo.c) of wship's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是猪猪海景别墅主人溟剑休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
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
    
        set("room_owner", "溟剑");
        set("room_name", "猪猪海景别墅");
        set("room_id", "villas");
        set("room_owner_id", "wship");
        set("room_position", "南海之滨");
}
