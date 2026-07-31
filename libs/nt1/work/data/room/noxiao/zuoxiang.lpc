// SN:6H9319_6eoTCi^:2
// File(/data/room/noxiao/zuoxiang.c) of noxiao's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是红尘居的左厢房，是客人居住的地方。虽然不算奢华，却也
布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结实，
使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "xiakedao");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "渡无");
        set("room_name", "红尘居");
        set("room_id", "bluesky");
        set("room_owner_id", "noxiao");
        set("room_position", "南海之滨");
}
