// SN:IU<KAL:eWTU[Sn]K
// File(/data/room/longer/yanwu1.c) of longer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药王山庄演武厅");
	set ("long", @LONG
这是药王山庄的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "药王");
        set("room_name", "药王山庄");
        set("room_id", "longroom");
        set("room_owner_id", "longer");
        set("room_position", "山路");
}
