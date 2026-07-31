// SN:O^^HJ\<FjOQ4]g9b
// File(/data/room/cloth/yanwu2.c) of cloth's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "布衣之家演武厅");
	set ("long", @LONG
这是布衣之家的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "布衣");
        set("room_name", "布衣之家");
        set("room_id", "cloth");
        set("room_owner_id", "cloth");
        set("room_position", "碎石小道");
}
