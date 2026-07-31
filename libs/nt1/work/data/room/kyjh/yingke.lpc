// SN:IUo\XLfDWO[gD:Jk
// File(/data/room/kyjh/yingke.c) of kyjh's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "爱巢迎客厅");
	set ("long", @LONG
这里是爱巢的主人快意江湖迎接八方来客的地方。大凡客人来拜
见快意江湖，少不得在这里寒暄叙话，了尽仰慕之情。东面通往一个
茶室，是主人陪同客人品尝天下名茶之处。 
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

        set("room_owner", "快意江湖");
        set("room_name", "爱巢");
        set("room_id", "home");
        set("room_owner_id", "kyjh");
        set("room_position", "三岔口");
}
