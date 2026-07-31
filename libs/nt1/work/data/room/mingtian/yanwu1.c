// SN:oh@Of43M7g[I]G1D
// File(/data/room/mingtian/yanwu1.c) of mingtian's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "笑天演武厅");
	set ("long", @LONG
这是笑天的演武厅，有时有些江湖朋友来会，想一试身手，就在
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

        set("room_owner", "明封波");
        set("room_name", "笑天");
        set("room_id", "ylms");
        set("room_owner_id", "mingtian");
        set("room_position", "碎石小道");
}
