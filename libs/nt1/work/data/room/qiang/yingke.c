// SN:?Rj7^5SU>0>HK=V?
// File(/data/room/qiang/yingke.c) of qiang's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "我家迎客厅");
	set ("long", @LONG
这里是我家的主人夏天迎接八方来客的地方。大凡客人来拜见夏
天，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "夏天");
        set("room_name", "我家");
        set("room_id", "bbs");
        set("room_owner_id", "qiang");
        set("room_position", "碎石小道");
}
