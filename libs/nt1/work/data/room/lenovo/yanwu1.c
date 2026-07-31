// SN:hN2\>=iB;JnadUKF
// File(/data/room/lenovo/yanwu1.c) of lenovo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "叹息谷演武厅");
	set ("long", @LONG
这是叹息谷的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "联想");
        set("room_name", "叹息谷");
        set("room_id", "sighh");
        set("room_owner_id", "lenovo");
        set("room_position", "山洪瀑布");
}
