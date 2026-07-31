// SN:GJUc]Nm]o5?>3N<>
// File(/data/room/xuan/yishiting.c) of xuan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是一间房子主人渡邪和重要人物商量江湖大事之处，正中有
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

        set("room_owner", "渡邪");
        set("room_name", "一间房子");
        set("room_id", "home");
        set("room_owner_id", "xuan");
        set("room_position", "名人堂");
}
