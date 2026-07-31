// SN:TPW9F6V=0DUU2_;l
// File(/data/room/gabriel/yingke.c) of gabriel's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "伊甸园迎客厅");
	set ("long", @LONG
这里是伊甸园的主人加百列迎接八方来客的地方。大凡客人来拜
见加百列，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "加百列");
        set("room_name", "伊甸园");
        set("room_id", "eden");
        set("room_owner_id", "gabriel");
        set("room_position", "青砖路");
}
