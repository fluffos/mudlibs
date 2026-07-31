// SN:KURNGd9GFDIU^6T9
// File(/data/room/youhao/yanwu2.c) of youhao's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "虎穴演武厅");
	set ("long", @LONG
这是虎穴的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
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

        set("room_owner", "澄化");
        set("room_name", "虎穴");
        set("room_id", "youhao");
        set("room_owner_id", "youhao");
        set("room_position", "碎石小道");
}
