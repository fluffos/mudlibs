// SN:A7[=Q8IcCNg^gP9g
// File(/data/room/deaddead/yanwu1.c) of deaddead's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "游乐场演武厅");
	set ("long", @LONG
这是游乐场的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "哈后来");
        set("room_name", "游乐场");
        set("room_id", "deaddead");
        set("room_owner_id", "deaddead");
        set("room_position", "碎石小道");
}
