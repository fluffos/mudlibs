// SN:g\:3G=HLB@g]]ZV6
// File(/data/room/xiaolang/yanwu2.c) of xiaolang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "彩虹居演武厅");
	set ("long", @LONG
这是彩虹居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "永远寂寞");
        set("room_name", "彩虹居");
        set("room_id", "caihong");
        set("room_owner_id", "xiaolang");
        set("room_position", "碎石小道");
}
