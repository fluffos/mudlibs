// SN:PN]^Z7Z?G5f2N;<h
// File(/data/room/xiaojian/youxiang.c) of xiaojian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set ("long", @LONG
这是剑府的右厢房，是客人居住的地方。虽然不算奢华，却也布
置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结实，
使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "east" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "木门", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "小剑");
        set("room_name", "剑府");
        set("room_id", "xiaojianfu");
        set("room_owner_id", "xiaojian");
        set("room_position", "树林");
}
