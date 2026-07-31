// SN:QOOh31L>M0Y8Si?7
// File(/data/room/newera/yanwu2.c) of newera's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "随便吧演武厅");
	set ("long", @LONG
这是随便吧的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "天下");
        set("room_name", "随便吧");
        set("room_id", "newerb");
        set("room_owner_id", "newera");
        set("room_position", "碎石小道");
}
