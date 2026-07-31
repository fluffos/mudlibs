// SN:@>_nIKmod_2jiTG=
// File(/data/room/princess/yanwu2.c) of princess's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天空之城演武厅");
	set ("long", @LONG
这是天空之城的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "新月");
        set("room_name", "天空之城");
        set("room_id", "skyheaven");
        set("room_owner_id", "princess");
        set("room_position", "南海之滨");
}
