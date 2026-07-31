// SN:AT\QYm69MQ>8C4^i
// File(/data/room/vampire/yingke.c) of vampire's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "古堡迎客厅");
	set ("long", @LONG
这里是古堡的主人将臣迎接八方来客的地方。大凡客人来拜见将
臣，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，是
主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "将臣");
        set("room_name", "古堡");
        set("room_id", "castle");
        set("room_owner_id", "vampire");
        set("room_position", "三岔口");
}
