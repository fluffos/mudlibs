// SN:Xm]aIYk2XE?IG[F6
// File(/data/room/westwind/yanwu1.c) of westwind's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "西风居演武厅");
	set ("long", @LONG
这是西风居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "西风");
        set("room_name", "西风居");
        set("room_id", "wind");
        set("room_owner_id", "westwind");
        set("room_position", "名人堂");
}
