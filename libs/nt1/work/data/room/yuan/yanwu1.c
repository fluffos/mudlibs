// SN:bW[5]g\bNI^I8l`1
// File(/data/room/yuan/yanwu1.c) of yuan's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "相国寺演武厅");
	set ("long", @LONG
这是相国寺的演武厅，有时有些江湖朋友来会，想一试身手，就
在这里比武较量。 
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

        set("room_owner", "唐僧");
        set("room_name", "相国寺");
        set("room_id", "yuan");
        set("room_owner_id", "yuan");
        set("room_position", "碎石小道");
}
