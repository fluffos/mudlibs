// SN:MA4n?34Nlj8Y<\YQ
// File(/data/room/xnx/yingke.c) of xnx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "霍格沃茨迎客厅");
	set ("long", @LONG
里面的入口大厅大得惊人，火把将石墙照得通明，房顶高得难以
想象，正面美丽的大理石楼梯通往楼上。[2;37;0m
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

        set("room_owner", "绛珠草");
        set("room_name", "霍格沃茨");
        set("room_id", "hgwc");
        set("room_owner_id", "xnx");
        set("room_position", "碎石小道");
}
