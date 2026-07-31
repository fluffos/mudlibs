// SN:HcS_ccNNM0G3d[8L
// File(/data/room/ouyd/yishiting.c) of ouyd's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是白驼山庄主人欧阳毒和重要人物商量江湖大事之处，正中
有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "欧阳毒");
        set("room_name", "白驼山庄");
        set("room_id", "ouyd");
        set("room_owner_id", "ouyd");
        set("room_position", "碎石小道");
}
