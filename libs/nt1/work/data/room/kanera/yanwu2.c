// SN:To6LT9jb\e_Z7^`>
// File(/data/room/kanera/yanwu2.c) of kanera's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "米虫的窝演武厅");
	set ("long", @LONG
这是米虫的窝的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "米虫");
        set("room_name", "米虫的窝");
        set("room_id", "kanera");
        set("room_owner_id", "kanera");
        set("room_position", "碎石小道");
}
