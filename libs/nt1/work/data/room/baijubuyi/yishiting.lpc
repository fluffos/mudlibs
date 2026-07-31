// SN:TPg6RE_PfA8?f0no
// File(/data/room/baijubuyi/yishiting.c) of baijubuyi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是土地庙主人白居不易和重要人物商量江湖大事之处，正中
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

        set("room_owner", "白居不易");
        set("room_name", "土地庙");
        set("room_id", "baijubuyi");
        set("room_owner_id", "baijubuyi");
        set("room_position", "碎石小道");
}
