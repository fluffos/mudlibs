// SN:j>Z>mb43LN9S>G:_
// File(/data/room/mimee/yingke.c) of mimee's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "东厂迎客厅");
	set ("long", @LONG
这里是东厂的主人小达子迎接八方来客的地方。大凡客人来拜见
小达子，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "小达子");
        set("room_name", "东厂");
        set("room_id", "easthome");
        set("room_owner_id", "mimee");
        set("room_position", "碎石小道");
}
