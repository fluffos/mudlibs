// SN:B>ECDodD=QECO@Tn
// File(/data/room/zhuyun/yishiting.c) of zhuyun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是猪猪的窝主人猪猪和重要人物商量江湖大事之处，正中有
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

        set("room_owner", "猪猪");
        set("room_name", "猪猪的窝");
        set("room_id", "piggy");
        set("room_owner_id", "zhuyun");
        set("room_position", "山路");
}
