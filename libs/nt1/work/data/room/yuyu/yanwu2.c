// SN:kG1=PVLARON?S]Vh
// File(/data/room/yuyu/yanwu2.c) of yuyu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "辟邪屋演武厅");
	set ("long", @LONG
这是辟邪屋的演武厅，有时有些江湖朋友来会，想一试身手，就
在这里比武较量。 
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

        set("room_owner", "郁郁");
        set("room_name", "辟邪屋");
        set("room_id", "yuyu");
        set("room_owner_id", "yuyu");
        set("room_position", "碎石小道");
}
