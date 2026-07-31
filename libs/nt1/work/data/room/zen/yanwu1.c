// SN:KO>BZXJ?RAKo6]8N
// File(/data/room/zen/yanwu1.c) of zen's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "火之屋演武厅");
	set ("long", @LONG
这是火之屋的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "火火");
        set("room_name", "火之屋");
        set("room_id", "zen");
        set("room_owner_id", "zen");
        set("room_position", "名人堂");
}
