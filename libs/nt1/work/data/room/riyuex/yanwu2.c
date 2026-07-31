// SN:hPSf]2>^n19k9hSZ
// File(/data/room/riyuex/yanwu2.c) of riyuex's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "日月潭演武厅");
	set ("long", @LONG
这是日月潭的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "蓝魔之泪");
        set("room_name", "日月潭");
        set("room_id", "riyue");
        set("room_owner_id", "riyuex");
        set("room_position", "碎石小道");
}
