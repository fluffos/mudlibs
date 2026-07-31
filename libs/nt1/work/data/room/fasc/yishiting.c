// SN:jGFoESPW;Flc9P4k
// File(/data/room/fasc/yishiting.c) of fasc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是天庭主人至尊宝和重要人物商量江湖大事之处，正中有不
少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。 
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "至尊宝");
        set("room_name", "天庭");
        set("room_id", "angel");
        set("room_owner_id", "fasc");
        set("room_position", "名人堂");
}
