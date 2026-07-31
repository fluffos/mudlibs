// SN:T4ZfTkYMlio<ihLV
// File(/data/room/lastlord/yishiting.c) of lastlord's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "议事厅");
	set ("long", @LONG
这就是乞丐窝主人摩诃流星和重要人物商量江湖大事之处，正中
有不少桌椅，侧面是屏风，厅堂中挂着两个条幅，两旁通往演武厅。
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "摩诃流星");
        set("room_name", "乞丐窝");
        set("room_id", "lord");
        set("room_owner_id", "lastlord");
        set("room_position", "树林");
}
