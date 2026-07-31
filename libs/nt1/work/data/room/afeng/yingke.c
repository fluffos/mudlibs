// SN:XDn`6PPMR2hH6dnc
// File(/data/room/afeng/yingke.c) of afeng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "狗洞迎客厅");
	set ("long", @LONG
这里是狗洞的主人阿峰迎接八方来客的地方。大凡客人来拜见阿
峰，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
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

        set("room_owner", "阿峰");
        set("room_name", "狗洞");
        set("room_id", "afeng");
        set("room_owner_id", "afeng");
        set("room_position", "三岔口");
}
