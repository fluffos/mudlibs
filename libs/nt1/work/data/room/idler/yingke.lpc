// SN:>@^J5DlUSE4YD4Bk
// File(/data/room/idler/yingke.c) of idler's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "太虚居迎客厅");
	set ("long", @LONG
这里是太虚居的主人元神出窍迎接八方来客的地方。大凡客人来
拜见元神出窍，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "元神出窍");
        set("room_name", "太虚居");
        set("room_id", "taixuju");
        set("room_owner_id", "idler");
        set("room_position", "山路");
}
