// SN:`^NeUW6KQo9RAY:i
// File(/data/room/jinx/yingke.c) of jinx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金鳞阁迎客厅");
	set ("long", @LONG
这里是金鳞阁的主人蕴龙心境迎接八方来客的地方。大凡客人来
拜见蕴龙心境，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "蕴龙心境");
        set("room_name", "金鳞阁");
        set("room_id", "jinlin");
        set("room_owner_id", "jinx");
        set("room_position", "碎石小道");
}
