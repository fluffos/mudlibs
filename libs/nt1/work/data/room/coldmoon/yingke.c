// SN:H57fP7VMBS<a^X_=
// File(/data/room/coldmoon/yingke.c) of coldmoon's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "广寒宫迎客厅");
	set ("long", @LONG
这里是广寒宫的主人灵月迎接八方来客的地方。大凡客人来拜见
灵月，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "灵月");
        set("room_name", "广寒宫");
        set("room_id", "coldmoon");
        set("room_owner_id", "coldmoon");
        set("room_position", "碎石小道");
}
