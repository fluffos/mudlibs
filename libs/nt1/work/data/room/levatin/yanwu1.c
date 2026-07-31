// SN:CHMchIXGjHT219ID
// File(/data/room/levatin/yanwu1.c) of levatin's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风中的雪花演武厅");
	set ("long", @LONG
这是风中的雪花的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "慕容伤");
        set("room_name", "风中的雪花");
        set("room_id", "piaodd");
        set("room_owner_id", "levatin");
        set("room_position", "碎石小道");
}
