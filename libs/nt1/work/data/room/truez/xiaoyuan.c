// SN:E^Lf6Qgoi>Q02VK>
// File(/data/room/truez/xiaoyuan.c) of truez's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水晶屋小院");
	set ("long", @LONG
一条[1;34m五[1;31m彩[1;35m玻[1;36m璃[2;37;0m铺筑的小路通向小屋[2;37;0m
LONG );

        set("room_key", "1 of truez");
	setup();

	set("exits", ([
                "out"    : "/d/xiakedao/xkroad3",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "酷房");
        set("room_name", "水晶屋");
        set("room_id", "crystalbox");
        set("room_owner_id", "truez");
        set("room_position", "平原小路");
}
