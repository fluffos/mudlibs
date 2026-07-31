// SN:KS@h4M]GfDQEj]mZ
// File(/data/room/lhc/yanwu1.c) of lhc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "大钱库演武厅");
	set ("long", @LONG
这是大钱库的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "灵狐宠");
        set("room_name", "大钱库");
        set("room_id", "bankchina");
        set("room_owner_id", "lhc");
        set("room_position", "青砖路");
}
