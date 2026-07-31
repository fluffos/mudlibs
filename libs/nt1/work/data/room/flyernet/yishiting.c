// SN:8ilK@:=oIdERl[Dj
// File(/data/room/flyernet/yishiting.c) of flyernet's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是桃花源主人大侠和重要人物商量江湖大事之处，正中有不
少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "大侠");
        set("room_name", "桃花源");
        set("room_id", "dragon");
        set("room_owner_id", "flyernet");
        set("room_position", "碎石小道");
}
