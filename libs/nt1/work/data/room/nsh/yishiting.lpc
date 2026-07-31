// SN:hmMmZamM95Ilk5dj
// File(/data/room/nsh/yishiting.c) of nsh's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是逆水寒潭主人欧阳逆水和重要人物商量江湖大事之处，正
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

        set("room_owner", "欧阳逆水");
        set("room_name", "逆水寒潭");
        set("room_id", "nsh");
        set("room_owner_id", "nsh");
        set("room_position", "碎石小道");
}
