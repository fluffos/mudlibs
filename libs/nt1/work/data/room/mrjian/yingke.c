// SN:8`J4nJJI^Ua9XChW
// File(/data/room/mrjian/yingke.c) of mrjian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "灵光居迎客厅");
	set ("long", @LONG
这里是灵光居的主人慕容灵迎接八方来客的地方。大凡客人来拜
见慕容灵，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "慕容灵");
        set("room_name", "灵光居");
        set("room_id", "lgju");
        set("room_owner_id", "mrjian");
        set("room_position", "碎石小道");
}
