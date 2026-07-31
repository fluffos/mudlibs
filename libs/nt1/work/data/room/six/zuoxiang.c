// SN:DoE7dAofQOE1j6<n
// File(/data/room/six/zuoxiang.c) of six's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是虎穴的左厢房，是客人居住的地方。虽然不算奢华，却也布
置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结实，
使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "playertown");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "渡段");
        set("room_name", "虎穴");
        set("room_id", "huxue");
        set("room_owner_id", "six");
        set("room_position", "青砖路");
}
