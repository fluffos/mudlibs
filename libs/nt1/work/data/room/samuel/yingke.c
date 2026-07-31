// SN:1YmUj3lB9KI<8Lkl
// File(/data/room/samuel/yingke.c) of samuel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "国王的家迎客厅");
	set ("long", @LONG
这里是国王的家的主人门托萨拉迎接八方来客的地方。大凡客人
来拜见门托萨拉，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "门托萨拉");
        set("room_name", "国王的家");
        set("room_id", "samuel");
        set("room_owner_id", "samuel");
        set("room_position", "碎石小道");
}
