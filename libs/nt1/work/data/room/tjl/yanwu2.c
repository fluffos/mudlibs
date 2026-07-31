// SN:dQ1PL\bDR0Gn_U_V
// File(/data/room/tjl/yanwu2.c) of tjl's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "日本桑拿房演武厅");
	set ("long", @LONG
这是日本桑拿房的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "羽柴秀吉");
        set("room_name", "日本桑拿房");
        set("room_id", "tjl");
        set("room_owner_id", "tjl");
        set("room_position", "碎石小道");
}
