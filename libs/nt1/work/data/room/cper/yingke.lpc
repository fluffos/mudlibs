// SN:jo3CXTak^\UUi>Kk
// File(/data/room/cper/yingke.c) of cper's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "笑笑居迎客厅");
	set ("long", @LONG
这里是笑笑居的主人段笑笑迎接八方来客的地方。大凡客人来拜
见段笑笑，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "段笑笑");
        set("room_name", "笑笑居");
        set("room_id", "xiaoju");
        set("room_owner_id", "cper");
        set("room_position", "树林");
}
