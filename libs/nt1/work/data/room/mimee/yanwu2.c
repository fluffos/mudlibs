// SN:ia8]8j<Z43eX>48h
// File(/data/room/mimee/yanwu2.c) of mimee's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "东厂演武厅");
	set ("long", @LONG
这是东厂的演武厅，有时有些江湖朋友来会，想一试身手，就在
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

        set("room_owner", "小达子");
        set("room_name", "东厂");
        set("room_id", "easthome");
        set("room_owner_id", "mimee");
        set("room_position", "碎石小道");
}
