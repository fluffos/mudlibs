// File(/data/room/luoyuna/yishiting.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set("long", "这就是小白居主人大白和重要人物商量江湖大事之处，正中有不
少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
");

	set("exits", ([
		"east"   : __DIR__"yanwu1",
		"west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
		"south"  : __DIR__"yingke",
	]));

	set("no_sleep_room", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
