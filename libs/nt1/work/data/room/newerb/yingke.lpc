// SN:CP6\7Of[52Ogm2n0
// File(/data/room/newerb/yingke.c) of newerb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "名字难取迎客厅");
	set ("long", @LONG
这里是名字难取的主人名字难取迎接八方来客的地方。大凡客人
来拜见名字难取，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
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

        set("room_owner", "名字难取");
        set("room_name", "名字难取");
        set("room_id", "newera");
        set("room_owner_id", "newerb");
        set("room_position", "碎石小道");
}
