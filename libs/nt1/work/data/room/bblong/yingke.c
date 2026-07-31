// SN:C?=6BE6^cMdh;<3X
// File(/data/room/bblong/yingke.c) of bblong's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "神龙居迎客厅");
	set ("long", @LONG
这里是神龙居的主人龙飞雪迎接八方来客的地方。大凡客人来拜
见龙飞雪，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
室，是主人陪同客人品尝天下名茶之处。 
LONG );

	set("exits", ([
		"north"  : __DIR__"yishiting",
                "south"  : __DIR__"zoudao",
                "east"   : __DIR__"chashi",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "龙飞雪");
        set("room_name", "神龙居");
        set("room_id", "bblong");
        set("room_owner_id", "bblong");
        set("room_position", "碎石小道");
}
