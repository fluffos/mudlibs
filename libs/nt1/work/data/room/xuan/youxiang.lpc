// SN:=g2gRJ<IX5QP:>SS
// File(/data/room/xuan/youxiang.c) of xuan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set ("long", @LONG
这是一间房子的右厢房，是客人居住的地方。虽然不算奢华，却
也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结
实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "east" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "木门", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "渡邪");
        set("room_name", "一间房子");
        set("room_id", "home");
        set("room_owner_id", "xuan");
        set("room_position", "名人堂");
}
