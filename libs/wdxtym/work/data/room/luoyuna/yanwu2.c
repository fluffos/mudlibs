// File(/data/room/luoyuna/yanwu2.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小白居演武厅");
	set("long", "这是小白居的演武厅，有时有些江湖朋友来会，想一试身手，就
在这里比武较量。
");

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

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
