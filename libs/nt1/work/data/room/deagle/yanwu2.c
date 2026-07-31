// SN:@CiZaiBVJcJgQc_U
// File(/data/room/deagle/yanwu2.c) of deagle's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "弹药库演武厅");
	set ("long", @LONG
这是弹药库的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "沙漠之鹰");
        set("room_name", "弹药库");
        set("room_id", "deagle");
        set("room_owner_id", "deagle");
        set("room_position", "山路");
}
