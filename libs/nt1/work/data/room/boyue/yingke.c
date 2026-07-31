// SN:IQYE8<e>S[Hn:Qoe
// File(/data/room/boyue/yingke.c) of boyue's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "月宫迎客厅");
	set ("long", @LONG
这里是月宫的主人伯月迎接八方来客的地方。大凡客人来拜见伯
月，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "伯月");
        set("room_name", "月宫");
        set("room_id", "boyue");
        set("room_owner_id", "boyue");
        set("room_position", "碎石小道");
}
