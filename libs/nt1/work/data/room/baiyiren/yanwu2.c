// SN::C3dH7mR1OK:U6VG
// File(/data/room/baiyiren/yanwu2.c) of baiyiren's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "广厦千万间演武厅");
	set ("long", @LONG
这是广厦千万间的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "恶人");
        set("room_name", "广厦千万间");
        set("room_id", "baiyiren");
        set("room_owner_id", "baiyiren");
        set("room_position", "碎石小道");
}
