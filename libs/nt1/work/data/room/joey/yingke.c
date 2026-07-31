// SN:D<XACTg7e<<Q3^gF
// File(/data/room/joey/yingke.c) of joey's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "不想回家迎客厅");
	set ("long", @LONG
这里是不想回家的主人容祖儿迎接八方来客的地方。大凡客人来
拜见容祖儿，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "容祖儿");
        set("room_name", "不想回家");
        set("room_id", "bxhj");
        set("room_owner_id", "joey");
        set("room_position", "三岔口");
}
