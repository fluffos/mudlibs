// SN:5`Cf10oH?n2DRn=E
// File(/data/room/als/zuoxiang.c) of als's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "左厢房");
	set ("long", @LONG
这是海德酒店的左厢房，是客人居住的地方。虽然不算奢华，却
也布置得非常舒适。一张床整齐干净，没有多少折纹，而窗帘厚大结
实，使屋内光线恰到好处。 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "unknow");

        create_door("west", "木门", "east", DOOR_CLOSED);

        set("room_owner", "灌汤包子");
        set("room_name", "海德酒店");
        set("room_id", "hotl");
        set("room_owner_id", "als");
        set("room_position", "名人堂");
}
