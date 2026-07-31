// SN:0S[lUC[nZ=17ccS:
// File(/data/room/qingmo/yanwu2.c) of qingmo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "阅微草堂演武厅");
	set ("long", @LONG
这是阅微草堂的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "成处鑫");
        set("room_name", "阅微草堂");
        set("room_id", "qingmo");
        set("room_owner_id", "qingmo");
        set("room_position", "碎石小道");
}
