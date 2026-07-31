// SN:f[\\_[>k`lYG9BWH
// File(/data/room/qsnx/yishiting.c) of qsnx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是老年俱乐部主人胡老头和重要人物商量江湖大事之处，正
中有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "胡老头");
        set("room_name", "老年俱乐部");
        set("room_id", "ltj");
        set("room_owner_id", "qsnx");
        set("room_position", "名人堂");
}
