// SN:g49UonE7Y1NANfa6
// File(/data/room/yundanfq/yingke.c) of yundanfq's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "创世神殿迎客厅");
	set ("long", @LONG
这里是创世神殿的主人渡云迎接八方来客的地方。大凡客人来拜
见渡云，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "渡云");
        set("room_name", "创世神殿");
        set("room_id", "godhall");
        set("room_owner_id", "yundanfq");
        set("room_position", "平原小路");
}
