// SN:fB[XKjD3hc=Cg<mA
// File(/data/room/aaron/yingke.c) of aaron's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金色时代迎客厅");
	set ("long", @LONG
这里是金色时代的主人一灯迎接八方来客的地方。大凡客人来拜
见一灯，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "一灯");
        set("room_name", "金色时代");
        set("room_id", "goldentime");
        set("room_owner_id", "aaron");
        set("room_position", "碎石小道");
}
