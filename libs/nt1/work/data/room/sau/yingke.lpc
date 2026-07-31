// SN:EPQR]O8Y?1?mQ?CK
// File(/data/room/sau/yingke.c) of sau's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "浪云吧迎客厅");
	set ("long", @LONG
这里是浪云吧的主人白云迎接八方来客的地方。大凡客人来拜见
白云，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "白云");
        set("room_name", "浪云吧");
        set("room_id", "sau");
        set("room_owner_id", "sau");
        set("room_position", "碎石小道");
}
