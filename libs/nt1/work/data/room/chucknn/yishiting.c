// SN:2@RO32\k9F@Y4Vb6
// File(/data/room/chucknn/yishiting.c) of chucknn's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是聊聊居主人金聊聊和重要人物商量江湖大事之处，正中有
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

        set("room_owner", "金聊聊");
        set("room_name", "聊聊居");
        set("room_id", "chucknn");
        set("room_owner_id", "chucknn");
        set("room_position", "树林");
}
