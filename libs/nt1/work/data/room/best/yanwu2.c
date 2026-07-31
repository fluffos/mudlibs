// SN:2=BD1<o?8F^A<=5Y
// File(/data/room/best/yanwu2.c) of best's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "萍萍的屋演武厅");
	set ("long", @LONG
这是萍萍的屋的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "黄萍萍");
        set("room_name", "萍萍的屋");
        set("room_id", "best");
        set("room_owner_id", "best");
        set("room_position", "山路");
}
