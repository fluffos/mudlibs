// SN:5V>;l2hm:PZ9<je0
// File(/data/room/iaojian/yanwu1.c) of iaojian's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药府演武厅");
	set ("long", @LONG
这是药府的演武厅，有时有些江湖朋友来会，想一试身手，就在
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

        set("room_owner", "药剑");
        set("room_name", "药府");
        set("room_id", "iaofu");
        set("room_owner_id", "iaojian");
        set("room_position", "碎石小道");
}
