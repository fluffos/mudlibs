// SN:HBSO^Mnekg5gn63@
// File(/data/room/runx/yanwu1.c) of runx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "魔神宫演武厅");
	set ("long", @LONG
这是魔神宫的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "魔神");
        set("room_name", "魔神宫");
        set("room_id", "runx");
        set("room_owner_id", "runx");
        set("room_position", "平原小路");
}
