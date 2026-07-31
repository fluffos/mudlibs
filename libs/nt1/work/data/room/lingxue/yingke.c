// SN:L@UIecW1aKIfe9OB
// File(/data/room/lingxue/yingke.c) of lingxue's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "精灵水境迎客厅");
	set ("long", @LONG
这里是精灵水境的主人灵雪迎接八方来客的地方。大凡客人来拜
见灵雪，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "灵雪");
        set("room_name", "精灵水境");
        set("room_id", "spirit");
        set("room_owner_id", "lingxue");
        set("room_position", "碎石小道");
}
