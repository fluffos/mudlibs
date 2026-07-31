// SN:3VVY>CAKf6_<K]2D
// File(/data/room/livewind/yingke.c) of livewind's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "雨飘零迎客厅");
	set ("long", @LONG
这里是雨飘零的主人飘零迎接八方来客的地方。大凡客人来拜见
飘零，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "飘零");
        set("room_name", "雨飘零");
        set("room_id", "livewind");
        set("room_owner_id", "livewind");
        set("room_position", "碎石小道");
}
