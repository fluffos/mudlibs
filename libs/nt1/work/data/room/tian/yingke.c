// SN:2oWHQ;A:Y`KBDNG^
// File(/data/room/tian/yingke.c) of tian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "往事如烟迎客厅");
	set ("long", @LONG
这里是往事如烟的主人美人多情迎接八方来客的地方。大凡客人
来拜见美人多情，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
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

        set("room_owner", "美人多情");
        set("room_name", "往事如烟");
        set("room_id", "tianya");
        set("room_owner_id", "tian");
        set("room_position", "碎石小道");
}
