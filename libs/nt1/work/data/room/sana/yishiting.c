// SN:6XNn:E2aoAG;a07g
// File(/data/room/sana/yishiting.c) of sana's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是青蛙的小窝主人欧阳青蛙和重要人物商量江湖大事之处，
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

        set("room_owner", "欧阳青蛙");
        set("room_name", "青蛙的小窝");
        set("room_id", "frog");
        set("room_owner_id", "sana");
        set("room_position", "碎石小道");
}
