// SN:?`RPi16`ZVP:8AW[
// File(/data/room/donb/yingke.c) of donb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "幽游白书迎客厅");
	set ("long", @LONG
这里是幽游白书的主人虚藏迎接八方来客的地方。大凡客人来拜
见虚藏，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "虚藏");
        set("room_name", "幽游白书");
        set("room_id", "donb");
        set("room_owner_id", "donb");
        set("room_position", "碎石小道");
}
