// SN:gn`B<fBkVVF3;UV>
// File(/data/room/small/yanwu1.c) of small's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "孤独演武厅");
	set ("long", @LONG
这是孤独的演武厅，有时有些江湖朋友来会，想一试身手，就在
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

        set("room_owner", "小双");
        set("room_name", "孤独");
        set("room_id", "small");
        set("room_owner_id", "small");
        set("room_position", "青砖路");
}
