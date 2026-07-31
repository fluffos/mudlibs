// SN:7VHQBfJ;oW@;kGBS
// File(/data/room/levatin/yingke.c) of levatin's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风中的雪花迎客厅");
	set ("long", @LONG
这里是风中的雪花的主人慕容伤迎接八方来客的地方。大凡客人
来拜见慕容伤，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "慕容伤");
        set("room_name", "风中的雪花");
        set("room_id", "piaodd");
        set("room_owner_id", "levatin");
        set("room_position", "碎石小道");
}
