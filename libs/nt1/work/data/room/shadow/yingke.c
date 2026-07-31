// SN:hRgEh<@7Te`mBoSe
// File(/data/room/shadow/yingke.c) of shadow's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "神影之穴迎客厅");
	set ("long", @LONG
这里是神影之穴的主人影子无敌迎接八方来客的地方。大凡客人
来拜见影子无敌，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "影子无敌");
        set("room_name", "神影之穴");
        set("room_id", "lightroom");
        set("room_owner_id", "shadow");
        set("room_position", "青砖路");
}
