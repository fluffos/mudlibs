// SN:JSUlBA7SlceG7Mm1
// File(/data/room/newerb/yishiting.c) of newerb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是名字难取主人名字难取和重要人物商量江湖大事之处，正
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

        set("room_owner", "名字难取");
        set("room_name", "名字难取");
        set("room_id", "newera");
        set("room_owner_id", "newerb");
        set("room_position", "碎石小道");
}
