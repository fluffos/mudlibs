// SN:mZMX9NC3E;kG18YK
// File(/data/room/halllan/yingke.c) of halllan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "哈哈屋迎客厅");
	set ("long", @LONG
这里是哈哈屋的主人哈妹迎接八方来客的地方。大凡客人来拜见
哈妹，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "哈妹");
        set("room_name", "哈哈屋");
        set("room_id", "hhw");
        set("room_owner_id", "halllan");
        set("room_position", "青砖路");
}
