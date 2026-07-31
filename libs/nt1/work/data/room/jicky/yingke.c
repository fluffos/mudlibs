// SN:AHRH<E[1X<Q[038I
// File(/data/room/jicky/yingke.c) of jicky's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "毛毛的家迎客厅");
	set ("long", @LONG
这里是毛毛的家的主人毛毛迎接八方来客的地方。大凡客人来拜
见毛毛，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "毛毛");
        set("room_name", "毛毛的家");
        set("room_id", "jicky");
        set("room_owner_id", "jicky");
        set("room_position", "碎石小道");
}
