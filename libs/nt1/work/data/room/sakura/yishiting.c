// SN:H?1eKV<kmikS:gDb
// File(/data/room/sakura/yishiting.c) of sakura's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是樱花大战主人真宫寺樱和重要人物商量江湖大事之处，正
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

        set("room_owner", "真宫寺樱");
        set("room_name", "樱花大战");
        set("room_id", "sakura");
        set("room_owner_id", "sakura");
        set("room_position", "碎石小道");
}
