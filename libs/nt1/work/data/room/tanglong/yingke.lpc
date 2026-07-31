// SN:MLSD[Cj6jfL:<^GZ
// File(/data/room/tanglong/yingke.c) of tanglong's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "苍龙之原迎客厅");
	set ("long", @LONG
这里是苍龙之原的主人唐龙迎接八方来客的地方。大凡客人来拜
见唐龙，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "唐龙");
        set("room_name", "苍龙之原");
        set("room_id", "dragonsoul");
        set("room_owner_id", "tanglong");
        set("room_position", "碎石小道");
}
