// SN:ih9[]g3`eeLMhgi9
// File(/data/room/feng/yingke.c) of feng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "听风阁迎客厅");
	set ("long", @LONG
这里是听风阁的主人青衣修罗迎接八方来客的地方。大凡客人来
拜见青衣修罗，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "青衣修罗");
        set("room_name", "听风阁");
        set("room_id", "feng");
        set("room_owner_id", "feng");
        set("room_position", "三岔口");
}
