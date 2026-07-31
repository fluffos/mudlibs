// SN:S95J7376W2h8RCHJ
// File(/data/room/lsm/yingke.c) of lsm's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "雷神之殿迎客厅");
	set ("long", @LONG
这里是雷神之殿的主人雷斯魔迎接八方来客的地方。大凡客人来
拜见雷斯魔，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
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

        set("room_owner", "雷斯魔");
        set("room_name", "雷神之殿");
        set("room_id", "lsm");
        set("room_owner_id", "lsm");
        set("room_position", "平原小路");
}
