// SN:MAUg4j:D47876LbS
// File(/data/room/array/yingke.c) of array's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天龙阵迎客厅");
	set ("long", @LONG
这里是天龙阵的主人艾汀迎接八方来客的地方。大凡客人来拜见
艾汀，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "艾汀");
        set("room_name", "天龙阵");
        set("room_id", "array");
        set("room_owner_id", "array");
        set("room_position", "名人堂");
}
