// SN:`5[`nPS>MZiJWFXG
// File(/data/room/newall/yingke.c) of newall's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "新居室迎客厅");
	set ("long", @LONG
这里是新居室的主人新人类迎接八方来客的地方。大凡客人来拜
见新人类，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "新人类");
        set("room_name", "新居室");
        set("room_id", "xjs");
        set("room_owner_id", "newall");
        set("room_position", "青砖路");
}
