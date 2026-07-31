// SN:L\<6[]D\6bmB`?cH
// File(/data/room/sana/yanwu2.c) of sana's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "青蛙的小窝演武厅");
	set ("long", @LONG
这是青蛙的小窝的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "欧阳青蛙");
        set("room_name", "青蛙的小窝");
        set("room_id", "frog");
        set("room_owner_id", "sana");
        set("room_position", "碎石小道");
}
