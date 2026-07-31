// SN:[][l5OgOTWjZgf81
// File(/data/room/princess/yingke.c) of princess's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天空之城迎客厅");
	set ("long", @LONG
这里是天空之城的主人新月迎接八方来客的地方。大凡客人来拜
见新月，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "新月");
        set("room_name", "天空之城");
        set("room_id", "skyheaven");
        set("room_owner_id", "princess");
        set("room_position", "南海之滨");
}
