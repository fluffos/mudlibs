// SN:f_[oUoR;^60a@SVo
// File(/data/room/steel/yingke.c) of steel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "太玄居迎客厅");
	set ("long", @LONG
这里是太玄居的主人魔影迎接八方来客的地方。大凡客人来拜见
魔影，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "魔影");
        set("room_name", "太玄居");
        set("room_id", "kok");
        set("room_owner_id", "steel");
        set("room_position", "树林");
}
