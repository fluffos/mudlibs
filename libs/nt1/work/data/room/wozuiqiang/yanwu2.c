// SN:\L<TkL?YO@`DlE2a
// File(/data/room/wozuiqiang/yanwu2.c) of wozuiqiang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天地花园演武厅");
	set ("long", @LONG
这是天地花园的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "血影");
        set("room_name", "天地花园");
        set("room_id", "wozuiqiang");
        set("room_owner_id", "wozuiqiang");
        set("room_position", "碎石小道");
}
