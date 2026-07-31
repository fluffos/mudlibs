// SN:J`2K3nHOcDI[?l\i
// File(/data/room/kely/yanwu1.c) of kely's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "云杉演武厅");
	set ("long", @LONG
这是云杉的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
LONG );

	set("exits", ([
                "west" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "胡杉");
        set("room_name", "云杉");
        set("room_id", "kely");
        set("room_owner_id", "kely");
        set("room_position", "碎石小道");
}
