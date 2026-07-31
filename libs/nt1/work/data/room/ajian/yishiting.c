// SN:b^?FR]NHR`\B\J2E
// File(/data/room/ajian/yishiting.c) of ajian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是龙盘江南主人啊健和重要人物商量江湖大事之处，正中有
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

        set("room_owner", "啊健");
        set("room_name", "龙盘江南");
        set("room_id", "longjn");
        set("room_owner_id", "ajian");
        set("room_position", "山路");
}
