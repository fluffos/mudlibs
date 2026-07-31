// SN:G]oS:gOGB8FZHO[d
// File(/data/room/dvd/yingke.c) of dvd's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小箱子迎客厅");
	set ("long", @LONG
这里是小箱子的主人胡乱搞迎接八方来客的地方。大凡客人来拜
见胡乱搞，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "胡乱搞");
        set("room_name", "小箱子");
        set("room_id", "box");
        set("room_owner_id", "dvd");
        set("room_position", "碎石小道");
}
