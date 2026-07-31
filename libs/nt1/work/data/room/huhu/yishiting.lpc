// SN:i0QcVPVFlea:>V:D
// File(/data/room/huhu/yishiting.c) of huhu's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是关外小屋主人胡归真和重要人物商量江湖大事之处，正中
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

        set("room_owner", "胡归真");
        set("room_name", "关外小屋");
        set("room_id", "huhu");
        set("room_owner_id", "huhu");
        set("room_position", "碎石小道");
}
