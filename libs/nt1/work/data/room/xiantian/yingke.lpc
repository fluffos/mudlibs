// SN:7?cg@^]HWWUG^oAo
// File(/data/room/xiantian/yingke.c) of xiantian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "猪猪村中屋迎客厅");
	set ("long", @LONG
这里是猪猪村中屋的主人先天功迎接八方来客的地方。大凡客人
来拜见先天功，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "先天功");
        set("room_name", "猪猪村中屋");
        set("room_id", "piggyi");
        set("room_owner_id", "xiantian");
        set("room_position", "碎石小道");
}
