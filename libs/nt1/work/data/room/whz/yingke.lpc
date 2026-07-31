// SN:^INZV3_OnIbK\P>H
// File(/data/room/whz/yingke.c) of whz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风丹雅阁迎客厅");
	set ("long", @LONG
这里是风丹雅阁的主人给我新鲜迎接八方来客的地方。大凡客人
来拜见给我新鲜，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
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

        set("room_owner", "给我新鲜");
        set("room_name", "风丹雅阁");
        set("room_id", "ansionyd");
        set("room_owner_id", "whz");
        set("room_position", "碎石小道");
}
