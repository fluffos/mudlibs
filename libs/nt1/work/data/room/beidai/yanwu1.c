// SN:CIAKI^FgXlhRNk2n
// File(/data/room/beidai/yanwu1.c) of beidai's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "背篼演武厅");
	set ("long", @LONG
这是背篼的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
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

        set("room_owner", "背带");
        set("room_name", "背篼");
        set("room_id", "beidai");
        set("room_owner_id", "beidai");
        set("room_position", "碎石小道");
}
