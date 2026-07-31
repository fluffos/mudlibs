// File(/data/room/luoyuna/youxiang.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set("long", "这是小白居的右厢房，是客人居住的地方。虽然不算奢华，却也
布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结实，
使屋内光线恰到好处。
");

	set("exits", ([
		"east" : __DIR__"zhongting",
	]));

	set("sleep_room", 1);
	set("no_fight", 1);

	create_door("east", "木门", "west", DOOR_CLOSED);

	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
