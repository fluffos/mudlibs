// SN:@NCn7C6m2Tki\TYQ
// File(/data/room/hzx/yingke.c) of hzx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "兰色心情迎客厅");
	set ("long", @LONG
这里是兰色心情的主人海之心迎接八方来客的地方。大凡客人来
拜见海之心，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
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

        set("room_owner", "海之心");
        set("room_name", "兰色心情");
        set("room_id", "blueheart");
        set("room_owner_id", "hzx");
        set("room_position", "树林");
}
