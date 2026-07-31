// SN:5G@iNM8aZOZ]45VO
// File(/data/room/xgangbj/yingke.c) of xgangbj's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天文馆迎客厅");
	set ("long", @LONG
这里是天文馆的主人唐小藏迎接八方来客的地方。大凡客人来拜
见唐小藏，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "唐小藏");
        set("room_name", "天文馆");
        set("room_id", "xgangbj");
        set("room_owner_id", "xgangbj");
        set("room_position", "碎石小道");
}
