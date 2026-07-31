// SN:9D_JJLBU=]ZZLBK@
// File(/data/room/remiel/yingke.c) of remiel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天使禁猎区迎客厅");
	set ("long", @LONG
这里是天使禁猎区的主人雷米尔迎接八方来客的地方。大凡客人
来拜见雷米尔，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "雷米尔");
        set("room_name", "天使禁猎区");
        set("room_id", "angelcage");
        set("room_owner_id", "remiel");
        set("room_position", "青砖路");
}
