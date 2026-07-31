// SN:X7EHKOLPId=^b_jD
// File(/data/room/zhuyun/yanwu1.c) of zhuyun's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "猪猪的窝演武厅");
	set ("long", @LONG
这是猪猪的窝的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "猪猪");
        set("room_name", "猪猪的窝");
        set("room_id", "piggy");
        set("room_owner_id", "zhuyun");
        set("room_position", "山路");
}
