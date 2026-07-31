// SN:i78A9Ob`:B_;2^9R
// File(/data/room/lonely/yingke.c) of lonely's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "高处不胜寒迎客厅");
	set ("long", @LONG
这里是高处不胜寒的主人高处不胜寒迎接八方来客的地方。大凡
客人来拜见高处不胜寒，少不得在这里寒暄叙话，了尽仰慕之情。东
面通往一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "高处不胜寒");
        set("room_name", "高处不胜寒");
        set("room_id", "lonely");
        set("room_owner_id", "lonely");
        set("room_position", "名人堂");
}
