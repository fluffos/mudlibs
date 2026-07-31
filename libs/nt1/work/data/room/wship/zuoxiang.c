// SN:44mIn:DD0<XD?h:E
// File(/data/room/wship/zuoxiang.c) of wship's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是猪猪海景别墅的左厢房，是客人居住的地方。虽然不算奢华，
却也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大
结实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "xiakedao");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "溟剑");
        set("room_name", "猪猪海景别墅");
        set("room_id", "villas");
        set("room_owner_id", "wship");
        set("room_position", "南海之滨");
}
