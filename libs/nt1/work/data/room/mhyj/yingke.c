// SN:DD5G3hThfHXe=lFZ
// File(/data/room/mhyj/yingke.c) of mhyj's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "千枝花坞迎客厅");
	set ("long", @LONG
这里是千枝花坞的主人梦幻妖精迎接八方来客的地方。大凡客人
来拜见梦幻妖精，少不得在这里寒暄叙话，了尽仰慕之情。东面通往
一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "梦幻妖精");
        set("room_name", "千枝花坞");
        set("room_id", "mhyj");
        set("room_owner_id", "mhyj");
        set("room_position", "名人堂");
}
