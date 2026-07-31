// SN:ZKYbnA6@C\7bSh]g
// File(/data/room/heart/yanwu1.c) of heart's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "琉璃香榭演武厅");
	set ("long", @LONG
这是琉璃香榭的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "舞莲");
        set("room_name", "琉璃香榭");
        set("room_id", "heart");
        set("room_owner_id", "heart");
        set("room_position", "树林");
}
