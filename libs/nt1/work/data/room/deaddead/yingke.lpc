// SN:Uf5V_nPk4gEPoDE2
// File(/data/room/deaddead/yingke.c) of deaddead's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "游乐场迎客厅");
	set ("long", @LONG
这里是游乐场的主人哈后来迎接八方来客的地方。大凡客人来拜
见哈后来，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "哈后来");
        set("room_name", "游乐场");
        set("room_id", "deaddead");
        set("room_owner_id", "deaddead");
        set("room_position", "碎石小道");
}
