// SN:H`WZX9CQ[j<1WeJC
// File(/data/room/tinger/yanwu2.c) of tinger's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "黎苑小筑演武厅");
	set ("long", @LONG
这是黎苑小筑的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "婷儿");
        set("room_name", "黎苑小筑");
        set("room_id", "liyuan");
        set("room_owner_id", "tinger");
        set("room_position", "碎石小道");
}
