// SN:3<]nCCfVPZjO^R\G
// File(/data/room/vampire/yanwu1.c) of vampire's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "古堡演武厅");
	set ("long", @LONG
这是古堡的演武厅，有时有些江湖朋友来会，想一试身手，就在
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

        set("room_owner", "将臣");
        set("room_name", "古堡");
        set("room_id", "castle");
        set("room_owner_id", "vampire");
        set("room_position", "三岔口");
}
