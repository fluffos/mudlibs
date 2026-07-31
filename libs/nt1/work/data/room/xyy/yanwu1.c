// SN::O3k6Pb38CYYdDBi
// File(/data/room/xyy/yanwu1.c) of xyy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "歪歪居演武厅");
	set ("long", @LONG
这是歪歪居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "段歪歪");
        set("room_name", "歪歪居");
        set("room_id", "xyy");
        set("room_owner_id", "xyy");
        set("room_position", "树林");
}
