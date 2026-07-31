// SN:_cFmiB\9YnXe:K_8
// File(/data/room/funlove/yanwu1.c) of funlove's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天与地演武厅");
	set ("long", @LONG
这是天与地的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "爱玩笑");
        set("room_name", "天与地");
        set("room_id", "funlove");
        set("room_owner_id", "funlove");
        set("room_position", "碎石小道");
}
