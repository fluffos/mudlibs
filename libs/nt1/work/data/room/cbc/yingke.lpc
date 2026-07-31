// SN:UABR:NmOk[SM4P\e
// File(/data/room/cbc/yingke.c) of cbc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "建设银行金库迎客厅");
	set ("long", @LONG
这里是建设银行金库的主人建设银行迎接八方来客的地方。大凡
客人来拜见建设银行，少不得在这里寒暄叙话，了尽仰慕之情。东面
通往一个茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "建设银行");
        set("room_name", "建设银行金库");
        set("room_id", "cbc");
        set("room_owner_id", "cbc");
        set("room_position", "碎石小道");
}
