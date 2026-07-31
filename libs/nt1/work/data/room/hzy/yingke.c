// SN:D^=H6[XT14m]MKlF
// File(/data/room/hzy/yingke.c) of hzy's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小楼听风雨迎客厅");
	set ("long", @LONG
这里是小楼听风雨的主人日啊迎接八方来客的地方。大凡客人来
拜见日啊，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "日啊");
        set("room_name", "小楼听风雨");
        set("room_id", "hzy");
        set("room_owner_id", "hzy");
        set("room_position", "碎石小道");
}
