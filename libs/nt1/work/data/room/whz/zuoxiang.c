// SN:9AH[o>YM\:IhZ<ma
// File(/data/room/whz/zuoxiang.c) of whz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是风丹雅阁的左厢房，是客人居住的地方。虽然不算奢华，却
也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结
实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "playertown");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "给我新鲜");
        set("room_name", "风丹雅阁");
        set("room_id", "ansionyd");
        set("room_owner_id", "whz");
        set("room_position", "碎石小道");
}
