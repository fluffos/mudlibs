// SN:iQ5TVEhZkaiZ7beo
// File(/data/room/gudaoxifen/yingke.c) of gudaoxifen's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "怀旧雅居迎客厅");
	set ("long", @LONG
这里是怀旧雅居的主人古道西风迎接八方来客的地方。大凡客人
来拜见古道西风，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "古道西风");
        set("room_name", "怀旧雅居");
        set("room_id", "benlong");
        set("room_owner_id", "gudaoxifen");
        set("room_position", "青砖路");
}
