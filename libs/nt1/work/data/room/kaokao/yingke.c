// SN:`lMXM2CK9AUX8S;9
// File(/data/room/kaokao/yingke.c) of kaokao's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "穿心居迎客厅");
	set ("long", @LONG
这里是穿心居的主人靠靠迎接八方来客的地方。大凡客人来拜见
靠靠，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "靠靠");
        set("room_name", "穿心居");
        set("room_id", "kaokao");
        set("room_owner_id", "kaokao");
        set("room_position", "碎石小道");
}
