// SN:om`>1[P@KGUT:SI_
// File(/data/room/dajianb/yingke.c) of dajianb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风之居迎客厅");
	set ("long", @LONG
这里是风之居的主人风二中迎接八方来客的地方。大凡客人来拜
见风二中，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "风二中");
        set("room_name", "风之居");
        set("room_id", "wind");
        set("room_owner_id", "dajianb");
        set("room_position", "山路");
}
