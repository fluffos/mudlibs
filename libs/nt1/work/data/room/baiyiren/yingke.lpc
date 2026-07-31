// SN:MRmGeUj?ZlaB17NI
// File(/data/room/baiyiren/yingke.c) of baiyiren's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "广厦千万间迎客厅");
	set ("long", @LONG
这里是广厦千万间的主人恶人迎接八方来客的地方。大凡客人来
拜见恶人，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "恶人");
        set("room_name", "广厦千万间");
        set("room_id", "baiyiren");
        set("room_owner_id", "baiyiren");
        set("room_position", "碎石小道");
}
