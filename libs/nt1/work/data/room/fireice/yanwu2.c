// SN:Gb_ZUeZh8]DhB=Gc
// File(/data/room/fireice/yanwu2.c) of fireice's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "云闲居演武厅");
	set ("long", @LONG
这是云闲居的演武厅，有时有些江湖朋友来会，想一试身手，就
在这里比武较量。 
LONG );

	set("exits", ([
                "east" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "水灵");
        set("room_name", "云闲居");
        set("room_id", "king");
        set("room_owner_id", "fireice");
        set("room_position", "树林");
}
