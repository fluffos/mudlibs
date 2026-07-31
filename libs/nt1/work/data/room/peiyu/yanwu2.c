// SN:^FX5a40[E4dbG=P3
// File(/data/room/peiyu/yanwu2.c) of peiyu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "杀人山庄演武厅");
	set ("long", @LONG
这是杀人山庄的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "俞佩玉");
        set("room_name", "杀人山庄");
        set("room_id", "peiyu");
        set("room_owner_id", "peiyu");
        set("room_position", "南海之滨");
}
