// SN:dhjB1<<ZX7YInbiS
// File(/data/room/jack/yingke.c) of jack's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "胖子的家迎客厅");
	set ("long", @LONG
这里是胖子的家的主人段胖子迎接八方来客的地方。大凡客人来
拜见段胖子，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "段胖子");
        set("room_name", "胖子的家");
        set("room_id", "jack");
        set("room_owner_id", "jack");
        set("room_position", "碎石小道");
}
