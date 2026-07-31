// SN:YWW:oGk]i?95YCQK
// File(/data/room/wen/yingke.c) of wen's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "听雨轩迎客厅");
	set ("long", @LONG
这里是听雨轩的主人叶落听风迎接八方来客的地方。大凡客人来
拜见叶落听风，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "叶落听风");
        set("room_name", "听雨轩");
        set("room_id", "wen");
        set("room_owner_id", "wen");
        set("room_position", "三岔口");
}
