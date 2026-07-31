// SN:^i0A8>^^@\e?[^]I
// File(/data/room/hero/yanwu2.c) of hero's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "英雄会馆演武厅");
	set ("long", @LONG
这是英雄会馆的演武厅，有时有些江湖朋友来会，想一试身手，
就在这里比武较量。 
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

        set("room_owner", "英雄");
        set("room_name", "英雄会馆");
        set("room_id", "hero");
        set("room_owner_id", "hero");
        set("room_position", "树林");
}
