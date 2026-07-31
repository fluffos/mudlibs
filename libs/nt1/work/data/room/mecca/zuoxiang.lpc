// SN:0a_b94;]NOdVW3G_
// File(/data/room/mecca/zuoxiang.c) of mecca's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是贝勒爷王府的左厢房，是客人居住的地方。虽然不算奢华，
却也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大
结实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "yangzhou");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "杨铁心");
        set("room_name", "贝勒爷王府");
        set("room_id", "palace");
        set("room_owner_id", "mecca");
        set("room_position", "草地");
}
