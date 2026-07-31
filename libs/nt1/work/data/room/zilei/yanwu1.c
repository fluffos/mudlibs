// SN:FSGdb@kS=o[M>d]E
// File(/data/room/zilei/yanwu1.c) of zilei's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "思念居演武厅");
	set ("long", @LONG
这是思念居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "紫雷");
        set("room_name", "思念居");
        set("room_id", "sinian");
        set("room_owner_id", "zilei");
        set("room_position", "名人堂");
}
