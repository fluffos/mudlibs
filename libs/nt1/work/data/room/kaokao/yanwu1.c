// SN:9_<86k1A\0i0L>fO
// File(/data/room/kaokao/yanwu1.c) of kaokao's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "穿心居演武厅");
	set ("long", @LONG
这是穿心居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "靠靠");
        set("room_name", "穿心居");
        set("room_id", "kaokao");
        set("room_owner_id", "kaokao");
        set("room_position", "碎石小道");
}
