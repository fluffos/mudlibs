// SN::a<g>LD@m>FToJO6
// File(/data/room/jinx/yanwu2.c) of jinx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金鳞阁演武厅");
	set ("long", @LONG
这是金鳞阁的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "蕴龙心境");
        set("room_name", "金鳞阁");
        set("room_id", "jinlin");
        set("room_owner_id", "jinx");
        set("room_position", "碎石小道");
}
