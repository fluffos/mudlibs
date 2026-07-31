// File(/data/room/luoyuna/yingke.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小白居迎客厅");
	set("long", "这里是小白居的主人大白迎接八方来客的地方。大凡客人来拜见
大白，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
是主人陪同客人品尝天下名茶之处。
");

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

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
