// SN:^V2\[YPTR68XW<WY
// File(/data/room/hun/yingke.c) of hun's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "鬼岛迎客厅");
	set ("long", @LONG
这里是鬼岛的主人鬼魂迎接八方来客的地方。大凡客人来拜见鬼
魂，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
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

        set("room_owner", "鬼魂");
        set("room_name", "鬼岛");
        set("room_id", "dao");
        set("room_owner_id", "hun");
        set("room_position", "三岔口");
}
