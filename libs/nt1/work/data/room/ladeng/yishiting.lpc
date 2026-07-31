// SN:hQmF:CR@>lSR`V>h
// File(/data/room/ladeng/yishiting.c) of ladeng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是基地总部主人本拉灯和重要人物商量江湖大事之处，正中
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

        set("room_owner", "本拉灯");
        set("room_name", "基地总部");
        set("room_id", "jdzb");
        set("room_owner_id", "ladeng");
        set("room_position", "碎石小道");
}
