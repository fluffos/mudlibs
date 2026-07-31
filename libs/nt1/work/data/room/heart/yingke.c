// SN:7]Y31IfEKmYS9=SK
// File(/data/room/heart/yingke.c) of heart's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "琉璃香榭迎客厅");
	set ("long", @LONG
这里是琉璃香榭的主人舞莲迎接八方来客的地方。大凡客人来拜
见舞莲，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶室，
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

        set("room_owner", "舞莲");
        set("room_name", "琉璃香榭");
        set("room_id", "heart");
        set("room_owner_id", "heart");
        set("room_position", "树林");
}
