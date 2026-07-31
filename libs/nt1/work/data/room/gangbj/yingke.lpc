// SN:WnVj;aI>IN8nP^l3
// File(/data/room/gangbj/yingke.c) of gangbj's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "三藏的庙迎客厅");
	set ("long", @LONG
这里是三藏的庙的主人唐三藏迎接八方来客的地方。大凡客人来
拜见唐三藏，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "唐三藏");
        set("room_name", "三藏的庙");
        set("room_id", "gangbj");
        set("room_owner_id", "gangbj");
        set("room_position", "寒水潭");
}
