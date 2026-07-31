// SN:ej63F80]_9<ScOiP
// File(/data/room/lhp/yingke.c) of lhp's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "冰风溪谷迎客厅");
	set ("long", @LONG
这里是冰风溪谷的主人少龙迎接八方来客的地方。大凡客人来拜
见少龙，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "少龙");
        set("room_name", "冰风溪谷");
        set("room_id", "ice");
        set("room_owner_id", "lhp");
        set("room_position", "树林");
}
