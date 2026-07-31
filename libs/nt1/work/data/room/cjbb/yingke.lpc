// SN:>HC\8L0i4A5:di?V
// File(/data/room/cjbb/yingke.c) of cjbb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小花猪迎客厅");
	set ("long", @LONG
这里是小花猪的主人小花猪迎接八方来客的地方。大凡客人来拜
见小花猪，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "小花猪");
        set("room_name", "小花猪");
        set("room_id", "cjbb");
        set("room_owner_id", "cjbb");
        set("room_position", "名人堂");
}
