// SN:?C8jDj<fniMf=16j
// File(/data/room/flydami/zuoxiang.c) of flydami's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是我的炼丹炉的左厢房，是客人居住的地方。虽然不算奢华，
却也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大
结实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "playertown");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "超大");
        set("room_name", "我的炼丹炉");
        set("room_id", "flydami");
        set("room_owner_id", "flydami");
        set("room_position", "碎石小道");
}
