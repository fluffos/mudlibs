// SN:O4D0iY04?>\cCQUK
// File(/data/room/hateny/yanwu1.c) of hateny's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "赏雪庐演武厅");
	set ("long", @LONG
这是赏雪庐的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "唐小僧");
        set("room_name", "赏雪庐");
        set("room_id", "hateny");
        set("room_owner_id", "hateny");
        set("room_position", "碎石小道");
}
