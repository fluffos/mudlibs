// SN:5bacY@JS3e8OQG`8
// File(/data/room/lastlord/yingke.c) of lastlord's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "乞丐窝迎客厅");
	set ("long", @LONG
这里是乞丐窝的主人摩诃流星迎接八方来客的地方。大凡客人来
拜见摩诃流星，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一
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

        set("room_owner", "摩诃流星");
        set("room_name", "乞丐窝");
        set("room_id", "lord");
        set("room_owner_id", "lastlord");
        set("room_position", "树林");
}
