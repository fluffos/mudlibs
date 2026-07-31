// SN:baQ[a;PfDkHC_dAk
// File(/data/room/disz/yanwu1.c) of disz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "第三梯队演武厅");
	set ("long", @LONG
这是第三梯队的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "杯子");
        set("room_name", "第三梯队");
        set("room_id", "disz");
        set("room_owner_id", "disz");
        set("room_position", "三岔口");
}
