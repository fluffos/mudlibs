// SN:Sj9Ai_[:F4;TnT>2
// File(/data/room/funlove/yishiting.c) of funlove's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是天与地主人爱玩笑和重要人物商量江湖大事之处，正中有
不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "爱玩笑");
        set("room_name", "天与地");
        set("room_id", "funlove");
        set("room_owner_id", "funlove");
        set("room_position", "碎石小道");
}
