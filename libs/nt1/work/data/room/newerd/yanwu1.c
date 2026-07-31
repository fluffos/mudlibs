// SN:DhdGF6P5o:@icPL7
// File(/data/room/newerd/yanwu1.c) of newerd's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "就是米演武厅");
	set ("long", @LONG
这是就是米的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "就是米");
        set("room_name", "就是米");
        set("room_id", "newerd");
        set("room_owner_id", "newerd");
        set("room_position", "碎石小道");
}
