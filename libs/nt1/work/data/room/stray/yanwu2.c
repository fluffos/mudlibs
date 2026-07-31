// SN:JZ\4JNk>ZJ2oc7M2
// File(/data/room/stray/yanwu2.c) of stray's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "米米米米演武厅");
	set ("long", @LONG
这是米米米米的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "我是米");
        set("room_name", "米米米米");
        set("room_id", "rice");
        set("room_owner_id", "stray");
        set("room_position", "青砖路");
}
