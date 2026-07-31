// SN:\_3E5?gm\77X0EE_
// File(/data/room/gmyr/yingke.c) of gmyr's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "流浪居迎客厅");
	set ("long", @LONG
这里是流浪居的主人伊人古墓迎接八方来客的地方。大凡客人来
拜见伊人古墓，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "伊人古墓");
        set("room_name", "流浪居");
        set("room_id", "gmyr");
        set("room_owner_id", "gmyr");
        set("room_position", "三岔口");
}
