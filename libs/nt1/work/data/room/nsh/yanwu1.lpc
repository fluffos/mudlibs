// SN:\F5?KhBYL2MSITO0
// File(/data/room/nsh/yanwu1.c) of nsh's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "逆水寒潭演武厅");
	set ("long", @LONG
这是逆水寒潭的演武厅，有时有些江湖朋友来会，想一试身手，
就在这里比武较量。 
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

        set("room_owner", "欧阳逆水");
        set("room_name", "逆水寒潭");
        set("room_id", "nsh");
        set("room_owner_id", "nsh");
        set("room_position", "碎石小道");
}
