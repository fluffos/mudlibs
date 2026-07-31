// SN:Xf;<Wc[cClE\^Wl?
// File(/data/room/youhao/yingke.c) of youhao's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "虎穴迎客厅");
	set ("long", @LONG
这里是虎穴的主人澄化迎接八方来客的地方。大凡客人来拜见澄
化，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
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

        set("room_owner", "澄化");
        set("room_name", "虎穴");
        set("room_id", "youhao");
        set("room_owner_id", "youhao");
        set("room_position", "碎石小道");
}
