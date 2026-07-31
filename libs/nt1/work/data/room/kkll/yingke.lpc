// SN:E[e=8Q]g=?F5fnVI
// File(/data/room/kkll/yingke.c) of kkll's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "宿舍迎客厅");
	set ("long", @LONG
这里是宿舍的主人龙七迎接八方来客的地方。大凡客人来拜见龙
七，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
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

        set("room_owner", "龙七");
        set("room_name", "宿舍");
        set("room_id", "kkll");
        set("room_owner_id", "kkll");
        set("room_position", "碎石小道");
}
