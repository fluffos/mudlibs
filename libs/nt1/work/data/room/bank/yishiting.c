// SN:[a`W]dT0QD2g@T6G
// File(/data/room/bank/yishiting.c) of bank's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是中国银行金库主人中国银行和重要人物商量江湖大事之处，
正中有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武
厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "中国银行");
        set("room_name", "中国银行金库");
        set("room_id", "bank");
        set("room_owner_id", "bank");
        set("room_position", "碎石小道");
}
