// SN:l`YokiAAZ698jigR
// File(/data/room/xsl/jusuo.c) of xsl's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是逍遥居主人陈小生休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "陈小生");
        set("room_name", "逍遥居");
        set("room_id", "xiaoyao");
        set("room_owner_id", "xsl");
        set("room_position", "碎石小道");
}
