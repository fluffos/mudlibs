// SN:AXm5aR;:>Lh\88P@
// File(/data/room/godkenny/yishiting.c) of godkenny's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是糖果点心屋主人云飘之翼和重要人物商量江湖大事之处，
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

        set("room_owner", "云飘之翼");
        set("room_name", "糖果点心屋");
        set("room_id", "candy");
        set("room_owner_id", "godkenny");
        set("room_position", "青石官道");
}
