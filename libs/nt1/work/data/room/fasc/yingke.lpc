// SN:SDH>Y<3cm3J]g>fP
// File(/data/room/fasc/yingke.c) of fasc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天庭迎客厅");
	set ("long", @LONG
这里是天庭的主人至尊宝迎接八方来客的地方。大凡客人来拜见
至尊宝，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "至尊宝");
        set("room_name", "天庭");
        set("room_id", "angel");
        set("room_owner_id", "fasc");
        set("room_position", "名人堂");
}
