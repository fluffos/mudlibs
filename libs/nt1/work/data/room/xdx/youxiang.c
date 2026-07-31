// SN:5PV4=@Q8nA^\;R7c
// File(/data/room/xdx/youxiang.c) of xdx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set ("long", @LONG
这是紫气山庄的右厢房，是客人居住的地方。虽然不算奢华，却
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

        set("room_owner", "净玄");
        set("room_name", "紫气山庄");
        set("room_id", "starg");
        set("room_owner_id", "xdx");
        set("room_position", "紫气台");
}
