// SN:8AmLMD8BSGK3\_bb
// File(/data/room/ghost/youxiang.c) of ghost's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "右厢房");
	set ("long", @LONG
这是天空之城的右厢房，是客人居住的地方。虽然不算奢华，却
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

        set("room_owner", "静香");
        set("room_name", "天空之城");
        set("room_id", "sky");
        set("room_owner_id", "ghost");
        set("room_position", "碎石小道");
}
