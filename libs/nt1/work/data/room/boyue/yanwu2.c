// SN:>\6OHXjSg1DO@QUm
// File(/data/room/boyue/yanwu2.c) of boyue's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "月宫演武厅");
	set ("long", @LONG
这是月宫的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
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

        set("room_owner", "伯月");
        set("room_name", "月宫");
        set("room_id", "boyue");
        set("room_owner_id", "boyue");
        set("room_position", "碎石小道");
}
