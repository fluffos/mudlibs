// SN:9O@@fT0@^e2C3MQ9
// File(/data/room/longer/yingke.c) of longer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药王山庄迎客厅");
	set ("long", @LONG
这里是药王山庄的主人药王迎接八方来客的地方。大凡客人来拜
见药王，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "药王");
        set("room_name", "药王山庄");
        set("room_id", "longroom");
        set("room_owner_id", "longer");
        set("room_position", "山路");
}
