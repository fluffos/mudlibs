// File(/data/room/luoyuna/lianwu.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set("long", "此处便是小白居的练武场，人在江湖，武功万万不可荒废。
");

	set("exits", ([
		"west" : __DIR__"houyuan",
	]));

        set("objects", ([
    	    "/clone/npc/mu-ren" : 4,
        ]));

	set("outdoors", "hell");
	set("no_sleep_room", 1);

	setup();
    
        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
