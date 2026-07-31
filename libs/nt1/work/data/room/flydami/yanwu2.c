// SN:4;TQ8@lX5iAWOAlm
// File(/data/room/flydami/yanwu2.c) of flydami's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "我的炼丹炉演武厅");
	set ("long", @LONG
这是我的炼丹炉的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "超大");
        set("room_name", "我的炼丹炉");
        set("room_id", "flydami");
        set("room_owner_id", "flydami");
        set("room_position", "碎石小道");
}
