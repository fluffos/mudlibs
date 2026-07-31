// SN:]\n3PT=:X[g>hmQ_
// File(/data/room/tan/yanwu1.c) of tan's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "似水年华演武厅");
	set ("long", @LONG
这是似水年华的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "明柳");
        set("room_name", "似水年华");
        set("room_id", "times");
        set("room_owner_id", "tan");
        set("room_position", "山洪瀑布");
}
