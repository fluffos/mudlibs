// SN:cdo6jK9Q?l5U6gKi
// File(/data/room/baijubuyi/yingke.c) of baijubuyi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "土地庙迎客厅");
	set ("long", @LONG
这里是土地庙的主人白居不易迎接八方来客的地方。大凡客人来
拜见白居不易，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "白居不易");
        set("room_name", "土地庙");
        set("room_id", "baijubuyi");
        set("room_owner_id", "baijubuyi");
        set("room_position", "碎石小道");
}
