// SN:BUn@h825n]_hUL@d
// File(/data/room/liufeng/yingke.c) of liufeng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风之城迎客厅");
	set ("long", @LONG
这里是风之城的主人流风迎接八方来客的地方。大凡客人来拜见
流风，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "流风");
        set("room_name", "风之城");
        set("room_id", "wind");
        set("room_owner_id", "liufeng");
        set("room_position", "树林");
}
