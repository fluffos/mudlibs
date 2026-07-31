// SN:P^ECNe_L3RAfoc5<
// File(/data/room/ajian/yingke.c) of ajian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "龙盘江南迎客厅");
	set ("long", @LONG
这里是龙盘江南的主人啊健迎接八方来客的地方。大凡客人来拜
见啊健，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "啊健");
        set("room_name", "龙盘江南");
        set("room_id", "longjn");
        set("room_owner_id", "ajian");
        set("room_position", "山路");
}
