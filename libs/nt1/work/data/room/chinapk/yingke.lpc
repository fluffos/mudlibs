// SN:?493XnUD<T>YZPOT
// File(/data/room/chinapk/yingke.c) of chinapk's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "肯德鸡迎客厅");
	set ("long", @LONG
这里是肯德鸡的主人肯德基迎接八方来客的地方。大凡客人来拜
见肯德基，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个茶
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

        set("room_owner", "肯德基");
        set("room_name", "肯德鸡");
        set("room_id", "chinapk");
        set("room_owner_id", "chinapk");
        set("room_position", "树林");
}
