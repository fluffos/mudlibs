// SN:lHcMjI_^_QoGoSQM
// File(/data/room/yangkang/yanwu1.c) of yangkang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "北京城演武厅");
	set ("long", @LONG
这是北京城的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "杨康");
        set("room_name", "北京城");
        set("room_id", "beijing");
        set("room_owner_id", "yangkang");
        set("room_position", "碎石小道");
}
