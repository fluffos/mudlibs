// SN:fMoM\AgE>33d1Z5M
// File(/data/room/ttttt/yingke.c) of ttttt's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "儿童乐园迎客厅");
	set ("long", @LONG
这里是儿童乐园的主人童童迎接八方来客的地方。大凡客人来拜
见童童，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "童童");
        set("room_name", "儿童乐园");
        set("room_id", "roomb");
        set("room_owner_id", "ttttt");
        set("room_position", "碎石小道");
}
