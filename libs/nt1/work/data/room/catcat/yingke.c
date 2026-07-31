// SN:D5n2l\5Ga?fJ7?jh
// File(/data/room/catcat/yingke.c) of catcat's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小段的家迎客厅");
	set ("long", @LONG
这里是小段的家的主人段吟雪迎接八方来客的地方。大凡客人来
拜见段吟雪，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
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

        set("room_owner", "段吟雪");
        set("room_name", "小段的家");
        set("room_id", "catcathome");
        set("room_owner_id", "catcat");
        set("room_position", "碎石小道");
}
