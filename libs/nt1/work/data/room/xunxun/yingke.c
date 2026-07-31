// SN:@_jfdYfN2IZ[X0HU
// File(/data/room/xunxun/yingke.c) of xunxun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "寻寻迎客厅");
	set ("long", @LONG
这里是寻寻的主人枪下蛋迎接八方来客的地方。大凡客人来拜见
枪下蛋，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "枪下蛋");
        set("room_name", "寻寻");
        set("room_id", "xunxun");
        set("room_owner_id", "xunxun");
        set("room_position", "青石官道");
}
