// SN:g@S2[eTWeA;2:VYf
// File(/data/room/wadefly/yingke.c) of wadefly's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "黯幽灵迎客厅");
	set ("long", @LONG
这里是黯幽灵的主人黯幽灵迎接八方来客的地方。大凡客人来拜
见黯幽灵，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "黯幽灵");
        set("room_name", "黯幽灵");
        set("room_id", "wadefly");
        set("room_owner_id", "wadefly");
        set("room_position", "碎石小道");
}
