// SN:E?bgR^^6DOEkKU`V
// File(/data/room/mecca/yanwu2.c) of mecca's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "贝勒爷王府演武厅");
	set ("long", @LONG
这是贝勒爷王府的演武厅，有时有些江湖朋友来会，想一试身手，
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

        set("room_owner", "杨铁心");
        set("room_name", "贝勒爷王府");
        set("room_id", "palace");
        set("room_owner_id", "mecca");
        set("room_position", "草地");
}
