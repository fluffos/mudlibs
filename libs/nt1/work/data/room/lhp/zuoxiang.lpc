// SN:=G4TZIb\n1]dYK^6
// File(/data/room/lhp/zuoxiang.c) of lhp's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是冰风溪谷的左厢房，是客人居住的地方。虽然不算奢华，却
也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结
实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "yangzhou");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "少龙");
        set("room_name", "冰风溪谷");
        set("room_id", "ice");
        set("room_owner_id", "lhp");
        set("room_position", "树林");
}
