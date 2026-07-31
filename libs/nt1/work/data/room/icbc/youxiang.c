// SN:ocg4DQb^TbdDAC4S
// File(/data/room/icbc/youxiang.c) of icbc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set ("long", @LONG
这是工商银行金库的右厢房，是客人居住的地方。虽然不算奢华，
却也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大
结实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "east" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "木门", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "工商银行");
        set("room_name", "工商银行金库");
        set("room_id", "icbc");
        set("room_owner_id", "icbc");
        set("room_position", "碎石小道");
}
